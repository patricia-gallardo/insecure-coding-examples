#include <cassert>
#include <climits>

/**
 * ES.104: Don’t underflow
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es104-dont-underflow
 */
static bool isSafe(int first, int second, int buf_len) {
  if (((second > 0) && (first < (INT_MIN + second))) ||
      ((second < 0) && (first > (INT_MAX + second)))) {
    return false;
  }
  // Signed Integer Underflow is Undefined Behavior
  int len_diff = first - second;
  return (len_diff <= buf_len);
}

int main() {
  assert(!isSafe(INT_MIN, 256, 256));
}