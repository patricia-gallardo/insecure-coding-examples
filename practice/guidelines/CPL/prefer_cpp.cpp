#include <algorithm>
#include <vector>
#include <iostream>

/**
 * CPL.1: Prefer C++ to C
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#cpl1-prefer-c-to-c
 */
int main() {
  std::vector<int> ages = {21, 84, 43, 22, 44, 87, 21, 98};
  std::sort(ages.begin(), ages.end());
  for (int age : ages)
    std::cout << age << " ";
}