#include <algorithm>
#include <array>
#include <iostream>
#include <string>

/**
 * ES.27: Use std::array or stack_array for arrays on the stack
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es27-use-stdarray-or-stack_array-for-arrays-on-the-stack
 */
int main() {
  std::array<std::string, 3> greetings =
    { "Hello", "Hi", "Aloha" };
  for (auto const & word : greetings)
    std::cout << word << " ";
  std::cout << "\n";

  std::sort(greetings.begin(), greetings.end());
  for (auto const & word : greetings)
    std::cout << word << " ";
  std::cout << "\n";
}