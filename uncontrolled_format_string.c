/**
 * Use of Externally-Controlled Format String
 * https://cwe.mitre.org/data/definitions/134.html
 */

#include <stdio.h>

int main(int argc, char * argv[]) {
  char * format = argv[1];
  char * str = argv[2];

  printf(format, str);
}