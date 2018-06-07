#include <stdio.h>

/**
 * Stack-based Buffer Overflow
 * https://cwe.mitre.org/data/definitions/121.html
 *
 * Use of Inherently Dangerous Function
 * https://cwe.mitre.org/data/definitions/242.html
 */
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
int main() {
    char buffer[10];
    gets(buffer); // <- Write outside
}