#include "fake_fork.h"

#include <setjmp.h>
#include <zconf.h>
#include <stdio.h>
#include <stdlib.h>

static int return_from_clone(void *arg) {
  jmp_buf *env_ptr = (jmp_buf *) arg;
  longjmp(*env_ptr, 1);
}

static pid_t clone_child(int flags, jmp_buf *env) {
  char stack_buf[PTHREAD_STACK_MIN];
  void *stack = stack_buf + sizeof(stack_buf);
  return clone(&return_from_clone, stack, flags, env);
}

void handle_error() {
  printf("* clone returned an error when parent %d tried to clone a child\n",
         getpid());
  exit(EXIT_SUCCESS);
}

pid_t fake_fork(int flags) {
  pid_t child_pid = 0;
  jmp_buf env;
  if (setjmp(env) == 0) {
    child_pid = clone_child(flags, &env);
    if (child_pid == -1) handle_error();
  }
  return child_pid;
}
