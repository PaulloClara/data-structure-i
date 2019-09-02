#include <stdio.h>
#include <stdlib.h>

int checkVector(int *v, int len, int val) {
  for (int i = 0; i < len; i++) {
    if (v[i] == val) {
      return 1;
    }
  }
  return 0;
}

void showVector(int *vector, int len, char *msg) {
  printf("%s => [ ", msg);
  for (int i = 0; i < len; i++) {
    printf("%d ", vector[i]);
  }
  printf("]\n");
}

int main () {
  int vectorA[6] = {0, 1, 4, 3, 4, 5};
  int lenVectorA = sizeof(vectorA)/sizeof(vectorA[0]);

  int vectorB[5] = {5, 1, 4, 5, 0};
  int lenVectorB = sizeof(vectorB)/sizeof(vectorB[0]);

  int vectorU[lenVectorA + lenVectorB];
  int iVectorU = 0;

  int vectorI[lenVectorA + lenVectorB / 2];
  int iVectorI = 0;

  for (int i = 0; i < lenVectorA; i++) {
    if (!checkVector(vectorU, iVectorU, vectorA[i])) {
      vectorU[iVectorU] = vectorA[i];
      iVectorU++;
    }
  }

  for (int i = 0; i < lenVectorB; i++) {
    if (!checkVector(vectorU, iVectorU, vectorB[i])) {
      vectorU[iVectorU] = vectorB[i];
      iVectorU++;
    } else {
      if (
        !checkVector(vectorI, iVectorI, vectorB[i])
        && checkVector(vectorA, lenVectorA, vectorB[i])
      ) {
        vectorI[iVectorI] = vectorB[i];
        iVectorI++;
      }
    }
  }

  showVector(vectorA, lenVectorA, "\n\nPrimeiro vetor");
  showVector(vectorB, lenVectorB, "Segundo vetor ");
  showVector(vectorU, iVectorU, "\nConjunto uniao");
  showVector(vectorI, iVectorI, "Conjunto intersecao");
  printf("\n\n");

  // system ("pause");
  return 0;
}
