/**
 * CWE-122: Heap-based Buffer Overflow
 * https://cwe.mitre.org/data/definitions/122.html
 */

#include <string.h>
#include <stdlib.h>

#define BUFSIZE 10
int main(int argc, char **argv) {
char *buf;
buf = (char *)malloc(sizeof(char)*BUFSIZE);
strcpy(buf, argv[1]);
}
