#include <cstdint>
#include <limits>
#include <numeric>
#include <iostream>

/**
 * Modified example from: https://en.cppreference.com/w/cpp/numeric/midpoint
 */
int main() {
  std::int32_t a = std::numeric_limits<std::int32_t>::max();
  std::int32_t b = std::numeric_limits<std::int32_t>::max() - 2;

  std::cout << "a: " << a << '\n'
            << "b: " << b << '\n'
            << "Incorrect (overflow and wrapping): " << (a + b) / 2 << '\n'
            << "Correct: " << std::midpoint(a, b) << '\n';
}