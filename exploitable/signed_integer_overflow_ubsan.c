/**
 * Integer Overflow or Wraparound
 * https://cwe.mitre.org/data/definitions/190.html
 */

#include <limits.h>
#include <stdio.h>

int main() {
  int first_len = INT_MAX;
  int second_len = 256;
  int buf_len = 256;
  // Signed Integer Overflow is Undefined Behavior
  int len_sum = first_len + second_len;
  if (len_sum <= buf_len) { // <- sum == 255
    printf("Sum of first and second length is %d\n", len_sum);
  }
}