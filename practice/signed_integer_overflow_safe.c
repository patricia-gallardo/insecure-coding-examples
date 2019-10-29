#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/**
 * Integer Overflow or Wraparound
 * https://cwe.mitre.org/data/definitions/190.html
 */
static bool isSafe(int first, int second, int buf_len) {
  if (((second > 0) && (first > (INT_MAX - second))) ||
      ((second < 0) && (first < (INT_MIN - second))))
    return false;
  // Signed Integer Overflow is Undefined Behavior
  int len_sum = first + second;
  return (len_sum <= buf_len);
}

int main() {
  assert(!isSafe(INT_MAX, 256, 256));
}
