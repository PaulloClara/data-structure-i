#include <stdio.h>
#include <stdlib.h>

void showVector(int *vector, int len, char *msg) {
  printf("%s => [ ", msg);
  for (int i = 0; i < len; i++) {
    printf("%d ", vector[i]);
  }
  printf("]\n");
}

int main () {
  int len;
  int aux;

  printf("Tamanho do vetor\n> ");
  scanf("%i", &len);

  int vector[len];
  int orderedVector[len];

  for (int i = 0; i < len; i++) {
    printf("Elemento da posicao %d\n> ", i);
    scanf("%i", &vector[i]);
  }

  printf("\n\n");

  showVector(vector, len, "Vetor");

  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (vector[i] > vector[j]) {
        aux = vector[i];
        vector[i] = vector[j];
        vector[j] = aux;
      }
    }
  }

  showVector(vector, len, "Vetor Crescente");

  printf("\n\n");
  // system ("PAUSE");

  return 0;
}
