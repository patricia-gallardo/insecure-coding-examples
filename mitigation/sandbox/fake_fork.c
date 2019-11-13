#include "fake_fork.h"

#include <assert.h>
#include <setjmp.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <zconf.h>

#define bool_s(x) ((x) ? "true" : "false")

static int return_from_clone(void *arg) {
  jmp_buf *env_ptr = (jmp_buf *) arg;
  longjmp(*env_ptr, 1);
}

static pid_t clone_child(int flags, jmp_buf *env) {
  char stack_buf[PTHREAD_STACK_MIN];
  void *stack = stack_buf + sizeof(stack_buf);
  return clone(&return_from_clone, stack, flags | SIGCHLD, env);
}

void handle_error() {
  printf("* clone returned an error when parent %d tried to clone a child\n",
         getpid());
  exit(EXIT_FAILURE);
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

static int detatch(void *ignored) {
  (void) ignored;
  assert(chroot("/proc/self/fdinfo/") == 0);
  assert(chdir("/") == 0);
  _exit(EXIT_SUCCESS);
}

bool detach_in_child() {
  char stack_buf[PTHREAD_STACK_MIN];
  void *stack = stack_buf + sizeof(stack_buf);
  pid_t pid = clone(&detatch, stack, CLONE_FS | SIGCHLD, NULL);

  int status = -1;
  pid_t child_pid = waitpid(pid, &status, 0);

  bool same_pid = child_pid == pid;
  bool has_exited = WIFEXITED(status);
  bool was_successful = WEXITSTATUS(status) == EXIT_SUCCESS;
  bool has_detached = same_pid && has_exited && was_successful;

  if (!has_detached) {
    printf(
        "* detach failed: same_pid = %s has_exited = %s was_successful = %s\n",
        bool_s(same_pid), bool_s(has_exited), bool_s(was_successful));
  }

  return has_detached;
}
