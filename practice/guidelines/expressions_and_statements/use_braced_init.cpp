#include <climits>
#include <cstdint>
#include <limits>

/**
 * ES.49: If you must use a cast, use a named cast
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es49-if-you-must-use-a-cast-use-a-named-cast
 */
int main() {
  int32_t some_int32 = std::numeric_limits<int32_t>::max();
  int64_t some_int64 = std::numeric_limits<int64_t>::max();
  float some_float = std::numeric_limits<float>::max();
  double some_double = std::numeric_limits<double>::max();

  // Safe
  int64_t i64{ some_int32 };
  // Safe
  double d{ some_float };
  // warning: narrowing conversion of ‘some_int64’ from ‘int64_t’ to ‘int32_t’
  //int32_t i32{ some_int64 };
  // warning: narrowing conversion of ‘some_double’ from ‘double’ to ‘float’
  //float f{ some_double };
}