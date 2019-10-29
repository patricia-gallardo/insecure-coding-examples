#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/**
 * Integer Overflow or Wraparound
 * https://cwe.mitre.org/data/definitions/190.html
 */
bool isSafe(unsigned int first, unsigned int second, unsigned int buf_len) {
  if (UINT_MAX - second < first)
    return false;
  unsigned int len_sum = first + second;
  return (len_sum <= buf_len);
}

int main() {
  assert(!isSafe(UINT_MAX, 256, 256));
}
