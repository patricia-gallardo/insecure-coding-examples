/**
 * NL.11: Make literals readable
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#nl11-make-literals-readable
 */
struct Hours {
  explicit Hours(unsigned long long n) : num(n) {}
  unsigned long long num = 0;
  Hours operator+(const Hours& other) { return Hours(num + other.num); }
};

struct Days {
  explicit Days(unsigned long long n) : num(n) {}
  unsigned long long num = 0;
  Days operator+(const Days& other) { return Days(num + other.num); }
};

Hours operator "" _hours(unsigned long long num) { return Hours(num); }
Days operator "" _days(unsigned long long num) { return Days(num); }

int main() {
  //auto err = 24_hours + 7_days; // Compile error
  auto days = 4_days + 5_days;
  auto hours = 4_hours + 5_hours;
}