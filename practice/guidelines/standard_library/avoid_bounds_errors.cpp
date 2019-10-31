#include <array>
#include <iostream>
#include <algorithm>

/**
 * SL.con.3: Avoid bounds errors
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#slcon3-avoid-bounds-errors
 */
int main() {
  std::array<int, 10> zero_at_init{};
  for (int i : zero_at_init)
    std::cout << i;

  std::array<int, 10> needs_zeroing;
  needs_zeroing.fill(0);
  std::for_each(needs_zeroing.begin(), needs_zeroing.end(), 
                [](const int& n) { std::cout << n; });
}