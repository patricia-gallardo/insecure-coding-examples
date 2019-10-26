#include <stdio.h>
#include <stdbool.h>
#include <memory.h>

// Olve Maudal : Insecure C and C++
void launch_missiles(int n)
{
  printf("Launching %d missiles\n", n);
}

void authenticate_and_launch(void)
{
  int n_missiles = 2;
  bool allowaccess = false;
  char response[8];

  printf("Secret: ");
  gets(response);

  if (strcmp(response, "Joshua") == 0)
    allowaccess = true;

  if (allowaccess) {
    puts("Access granted");
    launch_missiles(n_missiles);
  }

  if (!allowaccess)
    puts("Access denied");
}

int main(void) {
  puts("WarGames MissileLauncher v0.1");
  authenticate_and_launch();
  puts("Operation complete");
}