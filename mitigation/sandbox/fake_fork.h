#ifndef INSECURE_CODING_EXAMPLES_FAKE_FORK_H
#define INSECURE_CODING_EXAMPLES_FAKE_FORK_H

#define _GNU_SOURCE

#include <sched.h>
#include <stdbool.h>

pid_t fake_fork(int clone_flags);

bool detach_in_child();

#endif //INSECURE_CODING_EXAMPLES_FAKE_FORK_H
