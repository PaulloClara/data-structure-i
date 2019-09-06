#include <stdio.h>
#include <stdlib.h>

int main() {
  int len = 11;
  char date[len];

  printf("\tEntre com a data no formato DD/MM/AAAA\n> ");
  fgets(date, 11, stdin);

  printf("\n%c%c", date[0], date[1]);

  if (date[3] == 48) {
    switch (date[4]) {
      case 49:
        printf(" de Janeiro");
        break;
      case 50:
        printf(" de Fevereiro");
        break;
      case 51:
        printf(" de Março");
        break;
      case 52:
        printf(" de Abril");
        break;
      case 53:
        printf(" de Maio");
        break;
      case 54:
        printf(" de Junho");
        break;
      case 55:
        printf(" de Julho");
        break;
      case 56:
        printf(" de Agosto");
        break;
      case 57:
        printf(" de Setembro");
        break;
    }
  } else {
    switch (date[4]) {
      case 48:
        printf(" de Outubro");
        break;
      case 49:
        printf(" de Novembro");
        break;
      case 50:
        printf(" de Dezembro");
        break;
    }
  }

  printf(" de %c%c%c%c\n", date[6], date[7], date[8], date[9]);

  return 0;
}
