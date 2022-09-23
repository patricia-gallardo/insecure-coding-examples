#include <string.h>

int main(int argc, char * argv[]) {
  char * point = strrchr(argv[1], ':');
  if (point)
    point[1] = '\0';
}
