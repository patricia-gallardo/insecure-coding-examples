#include <array>
#include <cstddef>
#include <iostream>

/**
 * SL.str.5: Use std::byte to refer to byte values that do not necessarily represent characters
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#slstr5-use-stdbyte-to-refer-to-byte-values-that-do-not-necessarily-represent-characters
 */
int main() {
  std::array<std::byte, 3> bytes = {
    std::byte{ 0x41 },
    std::byte{ 0x41 },
    std::byte{ 0x41 }
  };
  for (auto const & byte : bytes) {
    std::cout << static_cast<unsigned char>(byte) << "\n";
  }
}
