/**
 * Adapted from Hacking, the Art of Exploitation by Jon Erickson
 *
 * __do_global_dtors_aux_fini_array_entry + 8
 */

#include <stdio.h>
#include <stdlib.h>

static void cleanup(void) __attribute__ ((destructor));

int main() {
  printf("1\n");
  printf("2\n");
  exit(0);
}

void cleanup(void) {
  printf("3\n");
}