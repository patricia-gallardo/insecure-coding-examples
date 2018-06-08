#include <string.h>

/**
 * Buffer Underwrite ('Buffer Underflow')
 * https://cwe.mitre.org/data/definitions/124.html
 */
int main() {
  char src[12];
  strcpy(src, "Hello World");

  size_t length = strlen(src);

  int index = (length -1);
  while (src[index] != 'x') {
    src[index] = '\0';
    index--;
  }
}