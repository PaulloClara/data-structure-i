#include <stdio.h>
#include <stdlib.h>

int binaryForDecimal(int *vector, int len) {
  int result = 0;
  int resultPow = 1;

  for (int i = 0; i < len; i++) {
    if (vector[len - i - 1] != 0) {
      for (int j = 0; j < i; j++) {
        resultPow *= 2;
      }
      result += resultPow;
      resultPow = 1;
    }
  }

  return result;
}

int main () {
  int binary[8] = {1, 0, 1, 1, 0, 1, 1, 0};

  int decimal = 0;
  char hexadecimal[2];

  int vectorTemp[4];

  decimal = binaryForDecimal(binary, 8);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      vectorTemp[j] = binary[j + i * 4];
    }
    hexadecimal[i] = binaryForDecimal(vectorTemp, 4);
  }

  printf("\nDecimal => %d\n", decimal);

  printf("Hexadecimal => ");
  for (int i = 0; i < 2; i++) {
    printf("%X", hexadecimal[i]);
  }
  printf("\n\n");

  // system ("PAUSE");
  return 0;
}
