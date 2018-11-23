/**
 * CWE-121: Stack-based Buffer Overflow
 * https://cwe.mitre.org/data/definitions/121.html
 */

#include <string.h>

#define BUFSIZE 10
int main(int argc, char **argv) {
  char buf[BUFSIZE];
  strcpy(buf, argv[1]);
}
