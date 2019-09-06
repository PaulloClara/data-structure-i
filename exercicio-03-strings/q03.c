#include <stdio.h>
#include <stdlib.h>

#define len 9

int main() {
  char string[len];

  printf("\tEntre com a hora no formato HH:MM:SS\n> ");
  fgets(string, len, stdin);

  printf("\n\t%c%c hora(s), ", string[0], string[1]);

  printf("%c%c minuto(s) e ", string[3], string[4]);

  printf("%c%c segundo(s)\n\n", string[6], string[7]);

  return 0;
}
