#include <stdio.h>
#include <stdlib.h>

int main () {
  int len;

  printf("Quantidade de elementos\n> ");
  scanf("%i", &len);

  int vector[len];
  vector[0] = 0;
  vector[1] = 1;

  for (int i = 2; i < len; i++) {
    vector[i] = vector[i - 2] + vector[i - 1];
  }

  printf("\n\nSequência de Fibonacci => ");
  for (int i = 0; i < len; i++) {
    printf("%d ", vector[i]);
  }
  printf("\n\n");

  // system ("PAUSE");

  return 0;
}
