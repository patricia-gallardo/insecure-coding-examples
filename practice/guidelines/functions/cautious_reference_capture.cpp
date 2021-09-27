#include <cassert>

/**
 * F.53: Avoid capturing by reference in lambdas that will be used
 * nonlocally, including returned, stored on the heap, or passed to
 * another thread
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rf-value-capture
 */
auto addNumber(int number) {
  return [number](int other) { return number + other; };
}
int main() {
  auto addTwo = addNumber(2);
  assert(addTwo(2) == 4);
}
