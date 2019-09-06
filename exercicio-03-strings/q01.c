#include <stdio.h>
#include <stdlib.h>

#define maxLen 300

int getLenVector(char *vector) {
  int len = 0;

  for (int i = 0; i < maxLen; i++) {
    if (vector[i] == '\n') return len;
    len++;
  }

  return len;
}

int main() {
  char string[maxLen];

  printf("\tEntre com a String\n> ");
  fgets(string, maxLen, stdin);

  int len = getLenVector(string);
  int aux;

  for (int i = 0; i < len; i++) {
    aux = string[len - i - 1];
    if (
      aux != 65 && aux != 69 && aux != 73 && aux != 79 && aux != 85 &&
      aux != 97 && aux != 101 && aux != 105 && aux != 111 && aux != 117 && aux != 32
    ) aux = 35;

    printf("%c", aux);
  }

  printf("\n");

  return 0;
}
