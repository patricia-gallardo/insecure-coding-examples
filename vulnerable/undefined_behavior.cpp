/**
 * From CppCon 2017: John Regehr “Undefined Behavior in 2017 (part 1 of 2)”
 * https://youtu.be/v1COuU2vU_w
 */

#include <iostream>
#include <limits.h>
using namespace std;

int foo(int x) {
 return (x + 1) > x;
}

int main() {
  cout << ((INT_MAX + 1) > INT_MAX) << "\n";
  cout << foo(INT_MAX) << "\n";
  return 0;
}
