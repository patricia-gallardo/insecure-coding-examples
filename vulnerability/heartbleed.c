#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * The below are simulations of the affected function in the HeartBleed vulnerability
 * They are from the following source repos:
 *
 * Vulnerable: https://www.openssl.org/source/openssl-1.0.1f.tar.gz
 * Fixed: https://www.openssl.org/source/openssl-1.0.1g.tar.gz
 *
 * Specifically the file: ssl/d1_both.c
 * Some of the stubbed out functions are copied from elsewhere in the openssl source
 *
 * The repos are covered by the the OpenSSL licence
 * https://www.openssl.org/source/license-openssl-ssleay.txt
 */

#define TLS1_RT_HEARTBEAT    24
#define TLS1_HB_REQUEST    1
#define TLS1_HB_RESPONSE  2
#define SSL3_RT_MAX_PLAIN_LENGTH    16384

#define n2s(c, s)  ((s=(((unsigned int)(c[0]))<< 8)| \
          (((unsigned int)(c[1]))    )),c+=2)
#define s2n(s, c)  ((c[0]=(unsigned char)(((s)>> 8)&0xff), \
        c[1]=(unsigned char)(((s)    )&0xff)),c+=2)

typedef struct RRec {
  unsigned char *data;
  int length;
} RRec;

typedef struct S3 {
  RRec rrec;
} S3;

typedef struct SSL {
  S3 *s3;

  void
  (*msg_callback)(int write_p, int version, int content_type, const void *buf,
                  size_t len, void *ssl, void *arg);

  void *msg_callback_arg;
  int version;
  unsigned int tlsext_hb_seq;
  unsigned int tlsext_hb_pending;
} SSL;

unsigned char *OPENSSL_malloc(unsigned int i) {
  printf("%s : %d bytes\n", __PRETTY_FUNCTION__, i);
  return malloc(i);
}

void OPENSSL_free(unsigned char *buffer) {
  free(buffer);
}

int RAND_pseudo_bytes(unsigned char *buf, int num) {}

void print_buffer(const unsigned char *buffer, int len) {
  for (int i = 0; i < len; i++) {
    printf("x\\%02x", buffer[i]);
  }
  printf("\n");
}

int dtls1_write_bytes(SSL *s, int type, unsigned char *buf, int len) {
  printf("Response : ");
  print_buffer(buf, len);
  return 0;
}

void dtls1_stop_timer(SSL *pSsl) {}

int
dtls1_process_heartbeat(SSL *s) {
  unsigned char *p = &s->s3->rrec.data[0], *pl;
  unsigned short hbtype;
  unsigned int payload;
  unsigned int padding = 16; /* Use minimum padding */

  /* Read type and payload length first */
  hbtype = *p++;
  n2s(p, payload);
  pl = p;

  if (s->msg_callback)
    s->msg_callback(0, s->version, TLS1_RT_HEARTBEAT,
                    &s->s3->rrec.data[0], s->s3->rrec.length,
                    s, s->msg_callback_arg);

  if (hbtype == TLS1_HB_REQUEST) {
    unsigned char *buffer, *bp;
    int r;

    /* Allocate memory for the response, size is 1 byte
     * message type, plus 2 bytes payload length, plus
     * payload, plus padding
     */
    buffer = OPENSSL_malloc(1 + 2 + payload + padding);
    bp = buffer;

    /* Enter response type, length and copy payload */
    *bp++ = TLS1_HB_RESPONSE;
    s2n(payload, bp);
    memcpy(bp, pl, payload);
    bp += payload;
    /* Random padding */
    RAND_pseudo_bytes(bp, padding);

    r = dtls1_write_bytes(s, TLS1_RT_HEARTBEAT, buffer, 3 + payload + padding);

    if (r >= 0 && s->msg_callback)
      s->msg_callback(1, s->version, TLS1_RT_HEARTBEAT,
                      buffer, 3 + payload + padding,
                      s, s->msg_callback_arg);

    OPENSSL_free(buffer);

    if (r < 0)
      return r;
  } else if (hbtype == TLS1_HB_RESPONSE) {
    unsigned int seq;

    /* We only send sequence numbers (2 bytes unsigned int),
     * and 16 random bytes, so we just try to read the
     * sequence number */
    n2s(pl, seq);

    if (payload == 18 && seq == s->tlsext_hb_seq) {
      dtls1_stop_timer(s);
      s->tlsext_hb_seq++;
      s->tlsext_hb_pending = 0;
    }
  }

  return 0;
}

int
dtls1_process_heartbeat_fixed(SSL *s) {
  unsigned char *p = &s->s3->rrec.data[0], *pl;
  unsigned short hbtype;
  unsigned int payload;
  unsigned int padding = 16; /* Use minimum padding */

  if (s->msg_callback)
    s->msg_callback(0, s->version, TLS1_RT_HEARTBEAT,
                    &s->s3->rrec.data[0], s->s3->rrec.length,
                    s, s->msg_callback_arg);

  /* Read type and payload length first */
  if (1 + 2 + 16 > s->s3->rrec.length)
    return 0; /* silently discard */
  hbtype = *p++;
  n2s(p, payload);
  if (1 + 2 + payload + 16 > s->s3->rrec.length)
    return 0; /* silently discard per RFC 6520 sec. 4 */
  pl = p;

  if (hbtype == TLS1_HB_REQUEST) {
    unsigned char *buffer, *bp;
    unsigned int write_length = 1 /* heartbeat type */ +
                                2 /* heartbeat length */ +
                                payload + padding;
    int r;

    if (write_length > SSL3_RT_MAX_PLAIN_LENGTH)
      return 0;

    /* Allocate memory for the response, size is 1 byte
     * message type, plus 2 bytes payload length, plus
     * payload, plus padding
     */
    buffer = OPENSSL_malloc(write_length);
    bp = buffer;

    /* Enter response type, length and copy payload */
    *bp++ = TLS1_HB_RESPONSE;
    s2n(payload, bp);
    memcpy(bp, pl, payload);
    bp += payload;
    /* Random padding */
    RAND_pseudo_bytes(bp, padding);

    r = dtls1_write_bytes(s, TLS1_RT_HEARTBEAT, buffer, write_length);

    if (r >= 0 && s->msg_callback)
      s->msg_callback(1, s->version, TLS1_RT_HEARTBEAT,
                      buffer, write_length,
                      s, s->msg_callback_arg);

    OPENSSL_free(buffer);

    if (r < 0)
      return r;
  } else if (hbtype == TLS1_HB_RESPONSE) {
    unsigned int seq;

    /* We only send sequence numbers (2 bytes unsigned int),
     * and 16 random bytes, so we just try to read the
     * sequence number */
    n2s(pl, seq);

    if (payload == 18 && seq == s->tlsext_hb_seq) {
      dtls1_stop_timer(s);
      s->tlsext_hb_seq++;
      s->tlsext_hb_pending = 0;
    }
  }

  return 0;
}

void test_openssl_1_0_1f(unsigned char *test_case, int len) {
  printf("\nTEST : %s\n", __PRETTY_FUNCTION__);
  SSL s;
  s.s3 = malloc(sizeof(S3));
  s.s3->rrec.data = test_case;
  s.s3->rrec.length = len;
  s.msg_callback = NULL;
  dtls1_process_heartbeat(&s);
}

void test_openssl_1_0_1g(unsigned char *test_case, int len) {
  printf("\nTEST : %s\n", __PRETTY_FUNCTION__);
  SSL s;
  s.s3 = malloc(sizeof(S3));
  s.s3->rrec.data = test_case;
  s.s3->rrec.length = len;
  s.msg_callback = NULL;
  dtls1_process_heartbeat_fixed(&s);
}

int main() {

  // 0x01fd -> 509

  {
    unsigned char test_case[] = "\x01\x01\xfd\x00";
    int len = (int) strlen(test_case);

    printf("\nRequest : ");
    print_buffer(test_case, len);

    test_openssl_1_0_1f(test_case, len);
    test_openssl_1_0_1g(test_case, len);
  }

  {
    unsigned char test_case[] = "\x01\x01\xfd\xde\xad\xbe\xef\xde\xad\xbe\xef\xde\xad\xbe\xef\xde\xad\xbe\xef\x00";
    int len = (int) strlen(test_case);

    printf("\nRequest : ");
    print_buffer(test_case, len);

    test_openssl_1_0_1f(test_case, len);
    test_openssl_1_0_1g(test_case, len);
  }
}
