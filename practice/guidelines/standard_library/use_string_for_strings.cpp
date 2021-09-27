#include <iostream>
#include <string>

/**
 * SL.str.1: Use std::string to own character sequences
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#slstr1-use-stdstring-to-own-character-sequences
 */

int main() {
  std::string first = "Hello ";
  std::string second = "World";
  std::string buffer = first + second;
  std::cout << buffer << "\n";
}
