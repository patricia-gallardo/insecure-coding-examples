/*
 * Adapted from Hacking, the Art of Exploitation by Jon Erickson
 * Turn off ASLR for a specific run
 * setarch `uname -m` -R ./getenvaddr PATH
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  if (argc < 3) {
    printf("Usage: %s <environment var> <binary> \n", argv[0]);
    exit(0);
  }

  char *pointer = getenv(argv[1]);

  printf("This name %s binary name %s\n", argv[0], argv[2]);
  int length_difference =  (strlen(argv[0]) - strlen(argv[2]))*2;
  printf("Length difference %d current pointer %p\n", length_difference, pointer);
  pointer += length_difference;
  printf("%s will be at %p\n", argv[1], pointer);
}
