#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool ConnectToMainframe(char *pwd) {
  return true;
}

bool GetPasswordFromUser(char *pwd, size_t pwd_size) {
  pwd = (char*) malloc(pwd_size * sizeof(char));
  strcpy(pwd, "My super secret password");
  return true;
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