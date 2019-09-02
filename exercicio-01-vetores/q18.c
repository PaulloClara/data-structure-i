#include <stdio.h>
#include <stdlib.h>

int main() {
  char carsName[5][30];
  float carsConsum[5];

  float consum;
  int smallerConsumIndex;
  float smallerConsumValue;

  for (int i = 0; i < 5; i++) {
    printf("\nVeiculo %d\n", i+1);

    printf("Nome: ");
    scanf("%s", &carsName[i]);

    printf("Km por litro: ");
    scanf("%f", &carsConsum[i]);
  }

  smallerConsumValue = 1000/carsConsum[0];
  smallerConsumIndex = 0;

  printf("\n\n\tRelatorio Final\n");
  for (int i = 0; i < 5; i++) {
    consum = 1000/carsConsum[i];

    if (consum < smallerConsumValue) {
      smallerConsumValue = consum;
      smallerConsumIndex = i;
    }

    printf("\t%d - %s - %.1f - %.1f Litros - R$ %.2f\n", i+1, carsName[i], carsConsum[i], consum, consum*2.25);
  }

  printf("\n\tO menor consumo é do %s.\n", carsName[smallerConsumIndex]);

  // system("pause");

  return 0;
}
