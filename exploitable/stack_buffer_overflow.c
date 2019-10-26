/**
 * Stack-based Buffer Overflow
 * https://cwe.mitre.org/data/definitions/121.html
 *
 * Use of Inherently Dangerous Function
 * https://cwe.mitre.org/data/definitions/242.html
 */

#include <stdio.h>

int main() {
  char buffer[10];
  char * ret = gets(buffer); // <- Write outside
}