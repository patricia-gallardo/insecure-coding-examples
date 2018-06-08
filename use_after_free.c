/**
 * Use After Free
 * https://cwe.mitre.org/data/definitions/416.html
 */

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  char* buffer = (char*)malloc (256);
  bool error = true;

  if (error)
    free(buffer);

  // [...]

  if (error)
    printf("%lu\n", strlen(buffer)); //<- Use after free
}