#include <stdio.h>
#include <stdlib.h>

int main() {
  float val;

  float allowance;
  float totalAllowance = 0;

  int minimums = 0;
  float maximum = 0;

  int len = 0;
  float salaryV[400];

  printf("\n\t\tProjecao de gastos com Abono\n");
  printf("\t============================================\n");

  do {
    printf("\tSalario: ");
    scanf("%f", &val);

    if (val > 0) {
      salaryV[len] = val;
      len++;
    }

  } while(val);

  printf("\n\tSalario - Abono\n");
  for (int i = 0; i < len; i++) {
    allowance = salaryV[i] * 0.20;

    if (allowance < 100) allowance = 100;
    if (allowance == 100) minimums++;
    if (allowance > maximum) maximum = allowance;

    totalAllowance += allowance;

    printf("\tR$ %.2f - R$ %.2f\n", salaryV[i], allowance);
  }

  printf("\n\t\tForam processados %d colaboradores\n", len);
  printf("\t\tTotal gasto com abonos: R$ %.2f\n", totalAllowance);
  printf("\t\tValor minimo pago a %d colaboradores\n", minimums);
  printf("\t\tMaior valor de abono pago: R$ %.2f\n", maximum);

  // system("pause");

  return 0;
}
