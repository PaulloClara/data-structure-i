#include <stdio.h>
#include <stdlib.h>

int main () {
  float valSale = 0;
  int numberOfSellers;
  int sellersVector[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

  printf("\n\nNumero de vendedores\n> ");
  scanf("%i", &numberOfSellers);

  for (int i = 0; i < numberOfSellers; i++) {
    printf("\nQuanto o vendedor %i conseguiu vender?\n> ", i+1);
    scanf("%f", &valSale);

    valSale = valSale * 0.09 + 200;

    printf("Esse vendedor recebeu $%.2f\n", valSale);

    if (valSale < 300) sellersVector[0] += 1;
    else if (valSale < 400) sellersVector[1] += 1;
    else if (valSale < 500) sellersVector[2] += 1;
    else if (valSale < 600) sellersVector[3] += 1;
    else if (valSale < 700) sellersVector[4] += 1;
    else if (valSale < 800) sellersVector[5] += 1;
    else if (valSale < 900) sellersVector[6] += 1;
    else if (valSale < 1000) sellersVector[7] += 1;
    else sellersVector[8] += 1;
  }

  printf("\n\n");
  for (int i = 0; i < 8; i++) {
    printf("%i receberam entre $%i00 e $%i99\n", sellersVector[i], i+2, i+2);
  }
  printf("%i receberam acima de $1000\n\n", sellersVector[8]);

  // system ("PAUSE");
  return 0;
}
