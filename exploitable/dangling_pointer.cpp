#include <iostream>
#include <string>
#include <string_view>

/**
 * Example by Kostya Serebryany in bug to LLVM (RESOLVED WONTFIX)
 * https://bugs.llvm.org/show_bug.cgi?id=34729
 *
 * clang++ -fsanitize=address -std=c++17 -o dangling_pointer dangling_pointer.cpp
 * ./dangling_pointer
 *
 * clang-tidy bugprone-dangling-handle
 */
int main() {
  std::string s = "Hellooooooooooooooo ";
  std::string_view sv = s + "World\n";
  std::cout << sv;
}