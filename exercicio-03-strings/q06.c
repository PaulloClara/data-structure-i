#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 200

int main() {
  char string[MAXLEN];
  size_t len;

  size_t words = 0;

  fprintf(stdout, "\n\tDigite alguma coisa\n> ");
  fgets(string, MAXLEN, stdin);
  string[strlen(string)-1] = '\0';
  len = strlen(string);

  if (string[0] != ' ') words++;

  for (size_t i = 0; i < len - 1; i++) {
    if (string[i] == ' ' && string[i+1] != ' ') words++;
  }

  printf("\n\n\t“%s“ tem [%d] caracteres e [%d] palavras!\n", string, len, words);

  return 0;
}
