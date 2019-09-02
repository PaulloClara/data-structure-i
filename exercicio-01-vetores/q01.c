#include <stdio.h>
#include <stdlib.h>

void showVector(int *vector, int len, char *msg) {
  printf("\t%s => [ ", msg);
  for (int i = 0; i < len; i++) {
    printf("%d ", vector[i]);
  }
  printf("]\n");
}

int main () {
  int len;

  printf("\nNumero de elementos do vetor A e B\n> ");
  scanf("%d", &len);

  int vectorA[len];
  int vectorB[len];
  int vectorC[len*2];

  for (int i = 0; i < len; i++) {
    printf("\nValor do vetor A na posicao %d\n> ", i);
    scanf("%d", &vectorA[i]);
  }

  for (int i = 0; i < len; i++) {
    printf("\nValor do vetor B na posicao %d\n> ", i);
    scanf("%d", &vectorB[i]);
  }

  for (int i = 0; i < len; i++) {
    vectorC[i] = vectorA[i];
    vectorC[i+len] = vectorB[i];
  }

  printf("\n\n");
  showVector(vectorA, len, "Vetor A");
  showVector(vectorB, len, "Vetor B");
  showVector(vectorC, len*2, "Vetor C");
  printf("\n\n");

  // system("pause");
  return 0;
}
