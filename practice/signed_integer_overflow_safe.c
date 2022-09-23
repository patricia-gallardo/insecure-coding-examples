#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/**
 * Integer Overflow or Wraparound
 * Signed Integer Overflow is Undefined Behavior
 * https://cwe.mitre.org/data/definitions/190.html
 */
static bool isSafe(int first, int second, int buf_len) {
  bool sec_neg = second < 0;
  bool sec_pos = second > 0;
  if ((sec_pos && (first > (INT_MAX - second))) ||
      (sec_neg && (first < (INT_MIN - second))))
    return false;
  int len_sum = first + second;
  return (len_sum <= buf_len);
}

int main() {
  assert(!isSafe(INT_MAX, 256, 256));
}
