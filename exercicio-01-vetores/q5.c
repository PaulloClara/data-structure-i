#include <stdio.h>
#include <stdlib.h>

void showVector(int *vector, int len, char *msg) {
  printf("%s => [ ", msg);
  for (int i = 0; i < len; i++) {
    printf("%d ", vector[i]);
  }
  printf("]\n");
}

int main() {
  int len;

  printf("Tamanho do vetor A\n> ");
  scanf("%i", &len);

  int vectorA[len];
  int vectorB[len];

  for (int i = 0; i < len; i++) {
    printf("Elemento da posicao %d\n> ", i);
    scanf("%i", &vectorA[i]);
  }

  for (int i = 0; i < len; i++) {
    if (vectorA[i] % 2) {
      vectorB[i] = 1;
    } else {
      vectorB[i] = 0;
    }
  }

  showVector(vectorA, len, "Vetor A");
  showVector(vectorB, len, "Vetor B");

  // system("PAUSE");
  return 0;
}
