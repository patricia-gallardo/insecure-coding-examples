/**
 * Integer Overflow or Wraparound
 * https://cwe.mitre.org/data/definitions/190.html
 */

#include <limits.h>
#include <stdio.h>

int main() {
  unsigned int first_len = UINT_MAX;
  unsigned int second_len = 256;
  unsigned int buf_len = 256;
  // !Not caught by tools! - Unsigned Integer Wraparound is Defined Behavior
  unsigned int len_sum = first_len + second_len;
  if (len_sum <= buf_len) { // <- sum == 255
    printf("Sum of first and second length is %d\n", len_sum);
  }
}
