#include <stdio.h>
#include <stdlib.h>

int main () {
  int len = 20;
  int vector[len];

  int sum = 0;

  for (int i = 0; i < len; i++) {
    printf("Valor da posicao %d\n> ", i);
    scanf("%d", &vector[i]);
  }

  for (int i = 0; i < len/2; i++) {
    sum += (vector[i] - vector[len-i-1]) * (vector[i] - vector[len-i-1]);
  }

  printf("\nSoma = %d\n\n", sum);

  // system("pause");
  return 0;
}
