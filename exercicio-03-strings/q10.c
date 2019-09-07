#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

size_t getSubstring(char *stringO, char *stringD, int start, int end) {
  size_t len = 0;

  for (size_t i = start; i < end; i++) {
    stringD[len++] = stringO[i];
  }

  return len;
}

int main() {
  char string[MAXLEN];

  int start;
  int end;

  fprintf(stdout, "\n\tDigite algo\n> ");
  fgets(string, MAXLEN, stdin);

  fprintf(stdout, "\n\tDigite a fatia no formato 0:1\n> ");
  scanf("%i:%i", &start, &end);

  char substring[end - start];
  size_t lenSub = getSubstring(string, substring, start, end);

  fprintf(stdout, "\n\n\tString digitada => %s", string);
  fprintf(stdout, "\tSubstring\t=> %s\ttam[%d]\n\n", substring, lenSub);

  return 0;
}
