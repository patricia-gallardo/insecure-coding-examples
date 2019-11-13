#ifndef INSECURE_CODING_EXAMPLES_FAKE_FORK_H
#define INSECURE_CODING_EXAMPLES_FAKE_FORK_H

#define _GNU_SOURCE

#include <sched.h>

pid_t fake_fork(int clone_flags);

#endif //INSECURE_CODING_EXAMPLES_FAKE_FORK_H
