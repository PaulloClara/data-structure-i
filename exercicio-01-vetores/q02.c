#include <stdio.h>
#include <stdlib.h>

void showVector(int *vector, int len, char *msg) {
  printf("\t%s => [ ", msg);
  for (int i = 0; i < len; i++) {
    printf("%d ", vector[i]);
  }
  printf("]\n");
}

int checkVector(int *v, int len, int val) {
  for (int i = 0; i < len; i++) {
    if (v[i] == val) {
      return 1;
    }
  }

  return 0;
}

int main () {
  int lenA, lenB;

  printf("\nNumero de elementos do vetor A\n> ");
  scanf("%d", &lenA);

  printf("\nNumero de elementos do vetor B\n> ");
  scanf("%d", &lenB);

  int lenU = lenA*lenB;
  int iU = 0;  // index uniao

  int lenI = (lenA+lenB)/2;
  int iI = 0;  // index intersecao

  int vectorA[lenA];
  int vectorB[lenB];

  int vectorU[lenU];
  int vectorI[lenI];

  for (int i = 0; i < lenA; i++) {
    printf("\nValor do vetor A na posicao %d\n> ", i);
    scanf("%d", &vectorA[i]);
  }

  for (int i = 0; i < lenB; i++) {
    printf("\nValor do vetor B na posicao %d\n> ", i);
    scanf("%d", &vectorB[i]);
  }

  for (int i = 0; i < lenA; i++) {
    if (!checkVector(vectorU, iU, vectorA[i])) {
      vectorU[iU] = vectorA[i];
      iU++;
    }
  }

  for (int i = 0; i < lenB; i++) {
    if (!checkVector(vectorU, iU, vectorB[i])) {
      vectorU[iU] = vectorB[i];
      iU++;
    } else {
      if (!checkVector(vectorI, iI, vectorB[i]) && checkVector(vectorA, lenA, vectorB[i])) {
        vectorI[iI] = vectorB[i];
        iI++;
      }
    }
  }

  printf("\n\n");
  showVector(vectorA, lenA, "Vetor A");
  showVector(vectorB, lenB, "Vetor B");
  printf("\n\n");
  showVector(vectorU, iU, "Conjunto uniao");
  showVector(vectorI, iI, "Conjunto intersecao");
  printf("\n\n");

  // system("pause");
  return 0;
}
