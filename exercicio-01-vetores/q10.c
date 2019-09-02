#include <stdio.h>
#include <stdlib.h>

int main () {
  int len = 0;
  int vector[200];
  // int vector[] = {}; Erro: acima de um elemento o vetor passa do limite alocado

  int val;
  float sum = 0;

  printf("\n\t0 - Stop\n\n");
  do {
    printf("Elemento da posica %pause\n> ", len);

    scanf("%d", &val);

    if (val > 0) {
      vector[len] = val;
      len++;
    }

  } while(val);

  for (int i = 0; i < len; i++) {
    sum += vector[i];
  }

  printf("\n\nSoma = %.2f\n", sum);
  printf("Media = %.2f\n\n", sum/len);

  // system("pause");

  return 0;
}
