/**
 * Improper Restriction of Operations within the Bounds of a Memory Buffer:
 * https://cwe.mitre.org/data/definitions/119.html
 */

// clang -g3 -fsanitize=address -o global_buffer_overflow global_buffer_overflow.c
int buffer[4] = {};
int main(void) {
  return buffer[4];
}