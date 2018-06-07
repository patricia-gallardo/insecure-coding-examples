#include <limits.h>
#include <string.h>

/**
 * Integer Overflow or Wraparound
 * https://cwe.mitre.org/data/definitions/190.html
 */
int main() {
    unsigned int first_len = UINT_MAX;
    unsigned int second_len = 256;
    unsigned int buf_len = 256;

    char first[first_len], second[second_len], buf[buf_len];

    if((first_len + second_len) <= 256) { // <- sum == 255
        memcpy(buf, first, first_len);
        memcpy(buf + first_len, second, second_len);
    }
}