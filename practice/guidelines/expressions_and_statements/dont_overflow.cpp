#include <cassert>
#include <climits>

/**
 * ES.103: Don’t overflow
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es103-dont-overflow
 */
static bool isSafe(int first, int second, int buf_len) {
  if (((second > 0) && (first > (INT_MAX - second))) ||
      ((second < 0) && (first < (INT_MIN - second)))) {
    return false;
  }
  // Signed Integer Overflow is Undefined Behavior
  int len_sum = first + second;
  return (len_sum <= buf_len);
}

int main() {
  assert(!isSafe(INT_MAX, 256, 256));
}
