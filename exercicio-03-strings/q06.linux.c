#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libs/getinput.h"

#define MAXLEN 200

int main() {
  char msg[] = " Caracteres digitados -> ";

  char string[MAXLEN];
  char *ptrString = string;
  int len;

  FILE *ptrArc = stdin;

  printf("\n\tDitire alguma coisa...\n");
  len = getInputAndCountChars(&ptrString, MAXLEN, msg, ptrArc);

  printf("\n\n\tA string “%s“ tem %d caracteres!\n\n", string, len);

  return 0;
}
