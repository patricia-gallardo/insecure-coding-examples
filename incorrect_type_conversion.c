/**
 * Incorrect Type Conversion or Cast
 * https://cwe.mitre.org/data/definitions/704.html
 */

#include <stdlib.h>

struct A {};
struct B {};

int main() {
  struct A * a = (struct A *) malloc (sizeof (struct A));
  struct B * b = (struct B *) a; // cast to unrelated type
}