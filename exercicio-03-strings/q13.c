#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

int main() {
  char binary[MAXLEN];
  size_t len;

  size_t decimal = 0;

  fprintf(stdout, "\t> Digite o valor em binario <\n> ");
  fgets(binary, MAXLEN, stdin);
  binary[strlen(binary)-1] = '\0';
  len = strlen(binary);

  size_t pow = 1;

  for (int i = 0; i < len; i++) {
    if (binary[len - i - 1] != '0') {
      for (int j = 0; j < i; j++) {
        pow *= 2;
      }
      decimal += pow;
      pow = 1;
    }
  }

  fprintf(stdout, "\n\n\tValor em binario [%s]\n", binary);
  fprintf(stdout, "\tValor em decimal [%d]\n\n\n", decimal);

  return 0;
}
