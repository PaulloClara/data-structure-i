#include <stdio.h>
#include <stdlib.h>

int main () {
  int player;
  int playersV[23] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int bestPlayer[2];
  int numberOfVotes = 0;

  do {
    printf("Numero do jogador: ");
    scanf("%d", &player);

    if (player > 0 && player < 24 ) {
      playersV[player - 1] += 1;
      numberOfVotes++;
    } else if (player > 23) printf("Voto invalido!\n");

  } while(player);

  printf("\n\nForam computados %d votos!\n\n", numberOfVotes);

  printf("Camisa | Votos | %\n");
  for (int i = 0; i < 23; i++) {
    if (!playersV[i]) continue;

    printf("  %d   ", i + 1);
    printf(" |   %d  ", playersV[i]);
    printf(" | %.1f %\n", playersV[i] * (100.0 / numberOfVotes));
  }

  bestPlayer[0] = playersV[0];
  bestPlayer[1] = 0;
  for (int i = 1; i < 23; i++) {
    if (playersV[i] > bestPlayer[0]) {
      bestPlayer[0] = playersV[i];
      bestPlayer[1] = i;
    }
  }

  printf(
    "\nO camisa %d foi o melhor jogador com %d votos, um total de %.1f %\n",
    bestPlayer[1] + 1, bestPlayer[0], bestPlayer[0] * (100.0 / numberOfVotes)
  );

  printf("\n\n");

  // system("pause");
  return 0;
}
