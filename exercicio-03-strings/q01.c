#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 300

size_t checkVowel(char ch) {
  switch (ch) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
      return 1;
    default:
      return 0;
  }
}

int main() {
  char string[MAXLEN];

  fprintf(stdout, "\n\tEntre com a String\n> ");
  fgets(string, MAXLEN, stdin);
  string[strlen(string)-1] = '\0';  // removendo quebra de linha

  size_t len = strlen(string);
  char ch;

  for (size_t i = 0; i < len; i++) {
    ch = string[len - i - 1];
    if (!checkVowel(ch) && ch != ' ') ch = '#';

    printf("%c", ch);
  }

  printf("\n\n");

  return 0;
}
