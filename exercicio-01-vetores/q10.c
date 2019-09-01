#include <stdio.h>
#include <stdlib.h>

int main () {
  int val = 1;

  int len = 0;
  int vector[] = {};

  float sum = 0;

  while (val) {
    printf("Elemento da posicao %i (0 para)\n> ", len);
    scanf("%i", &val);

    if (val) {
      vector[len] = val;
      len++;
    }
  }

  for (int i = 0; i < len; i++) {
    sum += vector[i];
  }

  printf("\n\nSoma = %.2f\n", sum);
  printf("Media = %.2f\n\n\n", sum / len);

  // system ("PAUSE");
  return 0;
}
