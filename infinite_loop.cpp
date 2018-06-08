/**
 * From StackOverflow : https://stackoverflow.com/questions/32506643/c-compilation-bug
 */

#include <iostream>
#include <complex>
using namespace std;

int main() {
  complex<int> delta;
  complex<int> mc[4] = {0};

  for(int di = 0; di < 4; di++, delta = mc[di]) {
    cout << di << endl;
  }

  return 0;
}