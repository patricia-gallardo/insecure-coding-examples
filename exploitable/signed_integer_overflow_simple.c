/**
 * Integer Overflow or Wraparound
 * https://cwe.mitre.org/data/definitions/190.html
 */

#include <limits.h>

int main() {
 int pos = INT_MAX;
 int offset = 256;
 int new_pos = pos + offset; // Signed Integer Overflow
 return 0;
}
