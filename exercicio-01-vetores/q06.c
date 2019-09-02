#include <stdio.h>
#include <stdlib.h>

int main () {
  int len;
  int bigger[2];
  int smaller[2];

  printf("Tamanho do vetor\n> ");
  scanf("%i", &len);

  int vector[len];

  for (int i = 0; i < len; i++) {
    printf("Elemento da posicao %d\n> ", i);
    scanf("%i", &vector[i]);
  }

  bigger[0] = vector[0];
  bigger[1] = 0;
  smaller[0] = vector[0];
  smaller[1] = 0;

  for (int i = 0; i < len; i++) {
    if (vector[i] > bigger[0]) {
      bigger[0] = vector[i];
      bigger[1] = i;
    } else {
      if (vector[i] < smaller[0]) {
        smaller[0] = vector[i];
        smaller[1] = i;
      }
    }
  }

  printf("\n\nVetor => [ ");
  for (int i = 0; i < len; i++) {
    printf("%d ", vector[i]);
  }
  printf("]\n\n");

  printf("O maior valor informado foi %d na posicao %d\n", bigger[0], bigger[1]);
  printf("O menor valor informado foi %d na posicao %d\n", smaller[0], smaller[1]);

  // system ("PAUSE");
  return 0;
}
