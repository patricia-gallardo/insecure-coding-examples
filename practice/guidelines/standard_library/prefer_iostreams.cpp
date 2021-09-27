#include <iostream>
#include <string>

/**
 * SL.io.3: Prefer iostreams for I/O
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#slio3-prefer-iostreams-for-io
 */
int main(int argc, char * argv[]) {
  std::string second;
  std::cin >> second;
  std::string first = argv[1];

  std::string buffer = first + second;
  std::cout << buffer << "\n";
}
