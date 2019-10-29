/**
 * Compiler Removal of Code to Clear Buffers
 * https://cwe.mitre.org/data/definitions/14.html
 */

#include <string.h>
#include <stdbool.h>
#include <stdio.h>

bool ConnectToMainframe(char *pwd) {
  printf("%s\n", pwd);
  return true;
}

bool GetPasswordFromUser(char *pwd, size_t pwd_size) {
  strncpy(pwd, "My super secret password", pwd_size);
  printf("%s\n", pwd);
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