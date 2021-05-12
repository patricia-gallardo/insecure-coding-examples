/**
 * NL.11: Make literals readable
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#nl11-make-literals-readable
 */
struct Pixels {
  explicit Pixels(unsigned long long n) : num(n) {}
  unsigned long long num = 0;
  Pixels operator+(const Pixels & other) { return Pixels(num + other.num); }
};

struct Percent {
  explicit Percent(unsigned long long n) : num(n) {}
  unsigned long long num = 0;
  Percent operator+(const Percent & other) { return Percent(num + other.num); }
};

Pixels operator "" _px(unsigned long long num) { return Pixels(num); }
Percent operator "" _percent(unsigned long long num) { return Percent(num); }

int main() {
  //auto width = 24_px + 7_percent; // Compile error
  auto percent = 4_percent + 5_percent;
  auto pixels = 4_px + 5_px;
}