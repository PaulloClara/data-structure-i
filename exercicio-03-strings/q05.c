#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 47  // Maior palavra pt-br tem 46 letras + fim de string

int main() {
  int len;
  char inputString[MAXLEN];

  printf("\n\tEntre com a palavra\n> ");
  fgets(inputString, MAXLEN, stdin);
  len = strlen(inputString) - 1;  // Deixando de contar com quebra de linha

  char originalString[len];
  char modifiedString[len];

  strncpy(originalString, inputString, len);

  for (int i = 0; i < len; i++) {
    modifiedString[i] = originalString[len - i - 1];
  }
  modifiedString[len] = 0; /* Fim de string \0 */

  printf("\n\n\n\t");

  if (!strcmp(originalString, modifiedString)) printf("É Palindroma!");
  else printf("Não é Palindroma!");

  printf("\n\n");

  return 0;
}
