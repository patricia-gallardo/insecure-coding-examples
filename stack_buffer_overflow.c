#include <stdio.h>

/**
 * https://cwe.mitre.org/data/definitions/121.html
 * https://cwe.mitre.org/data/definitions/242.html Use of Inherently Dangerous Function
 */
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
int main() {
    char buffer[10];
    gets(buffer); // <- Write outside
}