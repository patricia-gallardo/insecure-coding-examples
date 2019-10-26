/**
 * Shellcode
 * http://www-inst.eecs.berkeley.edu/~cs161/fa08/papers/stack_smashing.pdf
 */

#include <unistd.h>

int main(void) {
  char *name[2];
  name[0] = "/bin/sh";
  name[1] = NULL;
  execve(name[0], name, NULL);
}