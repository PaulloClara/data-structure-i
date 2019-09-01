#include <stdio.h>
#include <stdlib.h>

int main () {
  int len = 0;
  float sum = 0;
  float average = 0;
  float val = 1;
  float vetorNotas[] = {};

  while (val >= 0) {
    printf("\nValor da posicao %i\n> ", len);
    scanf("%f", &val);

    if (val >= 0) {
      vetorNotas[len] = val;
      sum += val;
      len++;
    }
  }

  average = sum / len;

  printf("\n\nForam lidos %i valores\n\n", len);

  printf("Os valores informados foram => [ ");
  for (int i = 0; i < len; i++) {
    printf("%.2f ", vetorNotas[i]);
  }
  printf("]\n\n");

  printf("Ordem inversa:\n");
  for (int i = 0; i < len; i++) {
    printf("%.2f\n", vetorNotas[len - i - 1]);
  }

  printf("\n\nOs valores somaram %.2f e a media obtida foi %.2f\n", sum, average);

  printf("\n\n");
  for (int i = 0; i < len; i++) {
    if (vetorNotas[i] > average) {
      printf("%.2f na posicao %i ficou acima da media\n", vetorNotas[i], i);
    }
  }

  printf("\n\n");
  for (int i = 0; i < len; i++) {
    if (vetorNotas[i] < 7) {
      printf("%.2f na posicao %i esta abaixo de 7\n", vetorNotas[i], i);
    }
  }

  printf("\n\nIsso é tudo perssuaul!\n\n");

  // system ("PAUSE");
  return 0;
}
