#include <stdio.h>
#include <stdlib.h>

void flushIn() {
  int ch;
  while((ch = fgetc(stdin)) != EOF && ch != '\n' ) {
    continue;
  }
}

int main() {
  char name[64];
  float sum = 0;
  float jumpVector[5];

  while (1) {
    printf("\nAtleta: ");
    fgets(name, sizeof(name), stdin);

    if (!name[1]) {
      return 0;
    }

    printf("\n");
    for (int i = 0; i < 5; i++) {
      switch (i) {
        case 0:
          printf("Primeiro Salto: ");
          break;
        case 1:
          printf("Segundo Salto: ");
          break;
        case 2:
          printf("Terceiro Salto: ");
          break;
        case 3:
          printf("Quarto Salto: ");
          break;
        case 4:
          printf("Quinto Salto: ");
          break;
      }
      scanf("%f", &jumpVector[i]);
      flushIn();
      sum += jumpVector[i];
    }

    printf("\nResultado final:\n");
    printf("Atleta: %s", name);
    printf("Saltos: ");
    for (int i = 0; i < 4; i++) {
      printf("%.1f - ", jumpVector[i]);
    }
    printf("%.1f\n", jumpVector[4]);

    printf("Media dos saltos: %.1f m\n", sum / 5);
  }
}
