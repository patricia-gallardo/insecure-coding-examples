/**
 * From StackOverflow : https://stackoverflow.com/questions/32506643/c-compilation-bug
 * g++ -O3 -o infinite_loop infinite_loop.cpp
 */

#include <iostream>
#include <complex>
using namespace std;

int main() {
  complex<int> next_value;
  complex<int> values[4] = {0};

  for (int i = 0; i < 4; i++, next_value = values[i]) {
    cout << i << endl;
  }
}
