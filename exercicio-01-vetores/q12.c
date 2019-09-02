#include <stdio.h>
#include <stdlib.h>

int main() {
  int len = 0;
  float sum = 0;
  float average = 0;

  float val;
  float scores[400];
  // float scores[] = {}; Erro!

  do {
    printf("\nValor da posicao %d\n> ", len);
    scanf("%f", &val);

    if (val >= 0) {
      scores[len] = val;
      sum += val;
      len++;
    }

  } while(val >= 0);

  average = sum / len;

  printf("\n\nForam lidos %d valores\n\n", len);

  printf("Os valores informados foram => [ ");
  for (int i = 0; i < len; i++) {
    printf("%.2f ", scores[i]);
  }
  printf("]\n\n");

  printf("Ordem inversa:\n");
  for (int i = 0; i < len; i++) {
    printf("%.2f\n", scores[len - i - 1]);
  }

  printf("\n\nOs valores somaram %.2f e a media obtida foi %.2f\n", sum, average);

  printf("\n\n");
  for (int i = 0; i < len; i++) {
    if (scores[i] > average) {
      printf("%.2f na posicao %d ficou acima da media\n", scores[i], i);
    }
  }

  printf("\n\n");
  for (int i = 0; i < len; i++) {
    if (scores[i] < 7) {
      printf("%.2f na posicao %d esta abaixo de 7\n", scores[i], i);
    }
  }

  printf("\n\nIsso é tudo perssuaul!\n\n");

  // system("pause");

  return 0;
}
