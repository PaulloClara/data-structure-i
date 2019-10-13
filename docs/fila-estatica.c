/*
*******************************************************************

Finalidade: Implementar uma fila estatica
Operacoes:
          - Entrar
          - Sair
          - Mostrar fila
          - Inicio da fila
          - Fim da fila
          - Tamanho da fila
          - Inicializacao da fila
          - Esvaziar a fila
          - Fila cheia
          - Fila vazia

*******************************************************************
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define tam 5

struct fila {
  int elemento[tam];
  int inicio, fim;
};

fila f1;

void inicializacao (fila *f) {

  f->inicio = -1;
  f->fim = -1;

}

bool filaCheia(fila *f) {

  bool retorno = false;
  if (f->fim == tam - 1) {
    retorno = true;
  }

  return retorno;

}

bool filaVazia(fila *f) {

  bool retorno = false;


  if (f->inicio == -1 && f->fim == -1) {
    retorno = true;
  }

  return retorno;

}

void tamanho (fila *f) {

  int tamanho;

  if (filaVazia(f)) {
    printf("\nFila vazia\n");
  }
  else {
    tamanho = (f->fim - f->inicio) + 1;
    printf("\nTamanho da fila: %i\n", tamanho);
  }
}

void consultarInicio (fila *f) {

  if (filaVazia(f)) {
    printf("\nFila vazia\n");
  }
  else {
    printf("\nInicio: %i", f->elemento[f->inicio]);
  }
}

void consultarFim (fila *f) {

  if (filaVazia(f)) {
    printf("\nFila vazia\n");
  }
  else {
    printf("\nFim: %i", f->elemento[f->fim]);
  }

}

void mostrarFila (fila *f) {

  int i;

  if (filaVazia(f)) {
    printf("\nFila vazia\n");
  }
  else {
    printf("\nFila: ");
    for (i = f->inicio; i <= f->fim; i = i + 1) {
      printf("%i ", f->elemento[i]);
    }
  }

}

void entrar (fila *f, int e) {

  if (filaVazia(f)) {
    f->inicio = f->inicio + 1;
  }
  f->fim = f->fim + 1;
  f->elemento[f->fim] = e;

}

int sair (fila *f) {

  int e;

	e = f->elemento[f->inicio];
  if (f->inicio == f->fim) {
    f->inicio = -1;
    f->fim = -1;
  }
  else {
    f->inicio = f->inicio + 1;
  }

  return e;

}

void esvaziarFila (fila *f) {

  int e;

  if (filaVazia(f)) {
    printf("\nFila vazia\n");
  }
  else {
    printf("\n\nEsvaziando fila\n");
    while (!filaVazia(f)) {
      e = sair(f);
      printf("\nElemento retirado: %i ", e);
    }
      printf("\nFila esvaziada\n");
  }

}

void menu() {

  char opcao;
  int e;

  inicializacao(&f1);

  do {
    system("cls");
    printf("FILA ESTATICA\n\n" );
    printf("1 - Entrar\n");
    printf("2 - Sair\n");
    printf("3 - Mostrar fila\n");
    printf("4 - Inicio da fila\n");
    printf("5 - Fim da fila\n");
    printf("6 - Tamanho da fila\n");
    printf("7 - Esvaziar fila\n");
    printf("0 - Sair do programa\n\n");
    printf("Opcao: ");
    opcao = getche();
    switch (opcao) {
      case '1' : {
        if (filaCheia(&f1)) {
          printf("\n\nFila cheia\n");
        }
        else {
          printf("\n\nElemento: ");
          scanf("%i", &e);
          entrar(&f1, e);
        }
        getch();
        break;
      }
      case '2' : {
        if (filaVazia(&f1)) {
          printf("\n\nFila vazia\n");
        }
        else {
          e = sair(&f1);
          printf("\n\nElemento removido: %i", e);
        }
        getch();
        break;
      }
      case '3' : {
        mostrarFila(&f1);
        getch();
        break;
      }
      case '4' : {
        consultarInicio(&f1);
        getch();
        break;
      }
      case '5' : {
        consultarFim(&f1);
        getch();
        break;
      }
      case '6' : {
        tamanho(&f1);
        getch();
        break;
      }
      case '7' : {
        esvaziarFila(&f1);
        getch();
        break;
      }
    }
  }
  while (opcao != '0');

}

// programa principal
int main() {

    menu();

}
// fim do programa
