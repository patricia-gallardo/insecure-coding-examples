// Example Code from cppreference.com
#include <utility>

int main() {
  static_assert(sizeof(int) == 4);

  static_assert(-1 > 1U);
  static_assert(0xFFFFFFFFU > 1U);
  static_assert(0xFFFFFFFFU == static_cast<unsigned>(-1));

  static_assert(std::cmp_less(-1, 1U));
  static_assert(std::cmp_less_equal(-1, 1U));
  static_assert(!std::cmp_greater(-1, 1U));
  static_assert(!std::cmp_greater_equal(-1, 1U));

  static_assert(-1 == 0xFFFFFFFFU);
  static_assert(std::cmp_not_equal(-1, 0xFFFFFFFFU));
}
