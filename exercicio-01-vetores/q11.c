#include <stdio.h>
#include <stdlib.h>

int main () {
  int moves[50];
  int resultVector[6] = {0};

  for (int i = 0; i < 50; i++) {
    printf("\nMovimento %i\n> ", i+1);
    scanf("%i", &moves[i]);
  }

  for (int i = 0; i < 50; i++) {
    resultVector[moves[i]-1] += 1;
  }

  printf("\n\nResultados:\n");
  for (int i = 0; i < 6; i++) {
    printf("Face %i marcou %.2f\n", i + 1, resultVector[i] / 50.00 * 100);
  }

  // system ("PAUSE");
  return 0;
}
