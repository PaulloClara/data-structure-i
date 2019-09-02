#include <stdio.h>
#include <stdlib.h>

int main () {
  int len;
  float sum = 0;

  printf("Tamanho do vetor\n> ");
  scanf("%i", &len);

  int vector[len];

  for (int i = 0; i < len; i++) {
    printf("Elemento da posicao %d\n> ", i);
    scanf("%i", &vector[i]);
  }

  for (int i = 0; i < len; i++) {
    sum += vector[i];
  }

  printf("\n\nSoma = %.2f\n", sum);
  printf("Media = %.2f\n\n\n", sum / len);

  // system ("PAUSE");
  return 0;
}
