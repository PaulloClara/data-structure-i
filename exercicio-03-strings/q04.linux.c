#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libs/getinput.h"

#define MAXLEN 17

int main() {
  char password[MAXLEN] = {0};
  char correctPassword[] = "adm";

  char *ptrPassword = password;
  FILE *ptrArc = stdin;

  int numberOfChars = 0;

  printf("\n\tEntre com a senha\n> ");
  getInputMaskingOutput(&ptrPassword, MAXLEN, '*', ptrArc);

  printf("\n\n\n\t");

  if (!strcmp(password, correctPassword)) printf("Senha CORRETA!");
  else printf("Senha INCORRETA!!!");

  printf("\n\n");

  return 0;
}
