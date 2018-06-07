#include <string.h>

/**
 * Buffer Underwrite ('Buffer Underflow')
 * https://cwe.mitre.org/data/definitions/124.html
 */
int main() {
  char src[] = "Hello World";
  size_t length = strlen(src);

  unsigned long index = (length -1);
  while (src[index] != 'x') {
    src[index] = '\0';
    index--;
  }
}