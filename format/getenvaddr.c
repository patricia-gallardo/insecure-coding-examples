/*
 * Adapted from Hacking, the Art of Exploitation by Jon Erickson
 * Turn off ASLR for a specific run
 * setarch `uname -m` -R ./getenvaddr PATH
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  if (argc < 2) {
    printf("Usage: %s <environment var> \n", argv[0]);
    exit(0);
  }

  printf("%s will be at %p\n", argv[1], getenv(argv[1]));
}
