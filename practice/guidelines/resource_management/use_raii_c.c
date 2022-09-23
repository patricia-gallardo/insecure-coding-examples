#include <stdlib.h>

#define RAII(func) __attribute__((cleanup(func)))
static inline void free_buffer(char ** buffer_ptr) {
  free(*buffer_ptr);
}
void process() {
  RAII(free_buffer) char * buffer = (char *)malloc(256);
}
