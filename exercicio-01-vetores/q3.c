#include <stdio.h>
#include <stdlib.h>

int main () {
  int vector[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 2, 4, 6, 8, 1, 3, 5, 7, 9};
  int len = 20;

  int s = 0;

  for (int i = 0; i < len / 2; i++) {
    s += (vector[i] - vector[len - i - 1]) * (vector[i] - vector[len - i - 1]);
  }

  printf("\nS = %d\n\n", s);

  // system ("pause");
  return 0;
}
