#include <stdlib.h>

#define RAII(func) __attribute__((cleanup(func)))
static inline void free_buffer(char ** buffer_ptr) {
  free(*buffer_ptr);
}
int main(void) {
  RAII(free_buffer) char * buffer = malloc(256);
}
