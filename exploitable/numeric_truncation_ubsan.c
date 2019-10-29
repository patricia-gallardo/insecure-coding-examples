/**
 * Numeric Truncation Error
 * https://cwe.mitre.org/data/definitions/197.html
 */

#include <limits.h>
#include <stdio.h>

int main() {
  unsigned int first_len = UINT_MAX - 256;
  unsigned int second_len = 256;
  int buf_len = 256;
  // !Not caught by tools! - Numeric Truncation is Implementation Defined Behavior
  int len_sum = first_len+second_len;
  if(len_sum <= buf_len) {
    printf("Sum of first and second length is %d\n", len_sum);
  }
}
