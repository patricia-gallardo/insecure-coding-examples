#include <cstring>
#include <limits>

// Comment out to test
#define constexpr

int main() {
  const int first_len = std::numeric_limits<int>::max();
  const int second_len = 256;
  const int buf_len = 256;
  char first[first_len], second[second_len], buf[buf_len];

  // Undefined behavior (negative)
  if constexpr ((first_len + second_len) <= buf_len) {
    memcpy(buf, first, first_len);
    memcpy(buf + first_len, second, second_len);
  }
}
