#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/**
 * Integer Overflow or Wraparound
 * https://cwe.mitre.org/data/definitions/190.html
 */
bool isSafe(unsigned int first_len,
            unsigned int second_len,
            unsigned int buf_len) {
  if (UINT_MAX - second_len < first_len)
    return false;
  unsigned int len_sum = first_len + second_len;
  return (len_sum <= buf_len);
}

int main() {
  assert(!isSafe(UINT_MAX, 256, 256));
}
