#include <algorithm>
#include <iostream>
#include <iterator>

/**
 * ES.1: Prefer the standard library to other libraries and to “handcrafted code”
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es1-prefer-the-standard-library-to-other-libraries-and-to-handcrafted-code
 */
int main() {
  std::string str = "Hello:World";
  // Predicate
  auto isColon = [](int ch) { return ch == ':'; };
  // The last element satisfying the predicate or the first element if not found
  // Searching from the end backwards
  auto first = std::find_if(std::rbegin(str), std::rend(str), isColon);
  std::cout << str << "\n";

  // If found - delete everything after
  if (first != std::rend(str))
    str.erase(first.base(), std::end(str));
  std::cout << str << "\n";
}
