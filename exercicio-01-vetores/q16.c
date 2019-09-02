#include <stdio.h>
#include <stdlib.h>

int main () {
  int so;
  int soV[6] = {0, 0, 0, 0, 0, 0};
  int bestSo[2];
  int numberOfVotes = 0;

  do {
    printf("\n\n");
    printf("1 - Windows Server\n");
    printf("2 - Unix\n");
    printf("3 - Linux\n");
    printf("4 - Netware\n");
    printf("5 - Mac OS\n");
    printf("6 - Outro\n");
    printf("0 - Parar\n> ");
    scanf("%d", &so);

    if (so > 0 && so < 7 ) {
      soV[so - 1] += 1;
      numberOfVotes++;
    } else if (so > 6) printf("Voto invalido!\n");

  } while(so);

  printf("\n\n\tSistema Operacional  Votos  %\n");

  printf("\t-------------------  -----  --\n");
  printf("\tWindows Server       %d      %d %\n", soV[0], soV[0] * (100 / numberOfVotes));
  printf("\tUnix                 %d      %d %\n", soV[1], soV[1] * (100 / numberOfVotes));
  printf("\tLinux                %d      %d %\n", soV[2], soV[2] * (100 / numberOfVotes));
  printf("\tNetware              %d      %d %\n", soV[3], soV[3] * (100 / numberOfVotes));
  printf("\tMac OS               %d      %d %\n", soV[4], soV[4] * (100 / numberOfVotes));
  printf("\tOutro                %d      %d %\n", soV[5], soV[5] * (100 / numberOfVotes));
  printf("\tTotal                %d\n", numberOfVotes);

  bestSo[0] = soV[0];
  bestSo[1] = 0;
  for (int i = 1; i < 6; i++) {
    if (soV[i] > bestSo[0]) {
      bestSo[0] = soV[i];
      bestSo[1] = i;
    }
  }

  printf("\nO sistema operacional mais votado foi o ");
  switch (bestSo[1]) {
    case 0:
      printf("Windows Server");
      break;
    case 1:
      printf("Unix");
      break;
    case 2:
      printf("Linux");
      break;
    case 3:
      printf("Netware");
      break;
    case 4:
      printf("Mac OS");
      break;
    case 5:
      printf("Outro");
      break;
  }

  printf(" com %d votos, somando %i %\n\n", bestSo[0], bestSo[0] * (100 / numberOfVotes));

  // system("pause");
  return 0;
}
