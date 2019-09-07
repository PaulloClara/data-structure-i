#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

size_t getPositionOfSubstrings(char *string, size_t len, size_t *positions) {
  size_t iPositions = 0;

  for (size_t i = 0; i < len; i++) {
    if (string[i] == 32) positions[iPositions++] = i;
  }

  return iPositions;
}

int main() {
  char name[MAXLEN];
  size_t lenName;

  size_t positions[MAXLEN/2];
  size_t lenPositions;

  size_t lenFirstName;
  size_t lenLastName;

  fprintf(stdout, "\n\tDigite um nome\n> ");
  fgets(name, MAXLEN, stdin);

  // Removendo quebra de linha
  lenName = strlen(name) - 1;
  // Obtendo posicao dos espacos na string e quantidade
  lenPositions = getPositionOfSubstrings(name, lenName, positions);

  // Primeiro espaco encontrado
  lenFirstName = positions[0];
  // Tamanho da string menos ultimo espaco encontrado menos o espaco
  lenLastName = lenName - positions[lenPositions-1] - 1;

  char firstName[lenFirstName];
  char lastName[lenLastName];

  for (size_t i = 0; i < lenFirstName; i++) {
    firstName[i] = name[i];
  }

  for (size_t i = 0; i < lenLastName; i++) {
    lastName[i] = name[lenName-lenLastName+i];
  }

  fprintf(stdout, "\n\t[%s/%s]\n\n", lastName, firstName);

  return 0;
}
