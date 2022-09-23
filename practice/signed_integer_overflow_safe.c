#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/**
 * Integer Overflow or Wraparound
 * Signed Integer Overflow is Undefined Behavior
 * https://cwe.mitre.org/data/definitions/190.html
 */
bool isSafe(int first_len, int second_len, int buf_len) {
  bool sec_pos = (second_len > 0);
  bool sec_neg = (second_len < 0);
  if ((sec_pos && (first_len > (INT_MAX - second_len))) ||
      (sec_neg && (first_len < (INT_MIN - second_len))))
    return false;
  int len_sum = first_len + second_len;
  return (len_sum <= buf_len);
}

int main() {
  assert(!isSafe(INT_MAX, 256, 256));
}
