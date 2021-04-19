#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/**
 * Numeric Truncation Error
 * https://cwe.mitre.org/data/definitions/197.html
 */
bool isSafe(unsigned int length, signed char * buf_len) {
  *buf_len = length;
  return true;
}

int main() {
  signed char buf_len = 0;
  assert(isSafe(UINT_MAX, &buf_len));
}
