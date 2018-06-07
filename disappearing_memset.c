#include <string.h>
#include <stdbool.h>

bool ConnectToMainframe(char *pwd) {
  return 0;
}

bool GetPasswordFromUser(char *pwd, size_t pwd_size) {
  return 0;
}

int main() {
  char pwd[64];
  if (GetPasswordFromUser(pwd, sizeof(pwd))) {
    if (ConnectToMainframe(pwd)) {
      // Interaction with mainframe
    }
  }
  memset(pwd, 0, sizeof(pwd)); // <- Removed by the optimizer
}