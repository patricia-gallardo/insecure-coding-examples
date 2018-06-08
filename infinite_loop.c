/**
 *
 */

#include <stdio.h>

int main() {
  int n = 0;
  int array[4] = {0};

  for (int i = 0; i < 4; i++, n = array[i]) {
    printf("%d\n", i);
  }
}