/*
  Feito e testado no Linux!
*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAXNOME 30

typedef struct posicao_s {
  int tempo;
  char nome[MAXNOME];
  struct posicao_s *proximo; 
} posicao_t;

typedef struct {
  int tamanho;
  posicao_t *inicio, *fim;
} fila_t;

void limpar_buffer() {
  char ch;
  while ((ch = fgetc(stdin)) != EOF && ch != '\n') continue;
}

void limpar_tela() {
  system("clear");
}

void iniciar_fila(fila_t *fila) {
  fila->tamanho = 0;
  fila->inicio = NULL;
  fila->fim = NULL;
}

void iniciar_posicao(posicao_t *posicao) {
  posicao->proximo = NULL;

  printf("\tNome do arquivo: ");
  scanf("%s", posicao->nome);
  limpar_buffer();

  printf("\tTempo necessario em segundos: ");
  scanf("%i", &posicao->tempo);
  limpar_buffer();
}

int fila_vazia(fila_t *fila) {
  return fila->tamanho == 0 ? TRUE : FALSE;
}

void adicionar(fila_t *fila) {
  posicao_t *posicao;

  posicao = (posicao_t*) malloc(sizeof(posicao_t));
  iniciar_posicao(posicao);

  if (fila_vazia(fila)) {
    fila->inicio = posicao;
    fila->fim = posicao;
  } else {
    fila->fim->proximo = posicao;
    fila->fim = posicao;
  }

  fila->tamanho++;
}

void remover(fila_t *fila) {
  posicao_t *posicao;

  if (fila->inicio == fila->fim) fila->fim = NULL;
  
  posicao = fila->inicio;

  fila->inicio = fila->inicio->proximo;
  fila->tamanho--;

  free(posicao);
}

void avancar(fila_t *fila, int *tempo_gasto) {
  if (fila_vazia(fila)) printf("\n\n\tFila Vazia!\n\n");
  else {
    fila->inicio->tempo--;
    (*tempo_gasto)++;

    if (fila->inicio->tempo <= 0) remover(fila);
  }
}

void mostrar(fila_t *fila) {
  posicao_t *posicao;

  if (fila_vazia(fila)) printf("\n\n\tFila Vazia!\n\n");
  else {
    posicao = fila->inicio;
    printf("\tPosicao - Nome - Tempo Necessario\n\n");
    for (size_t i = 0; i < fila->tamanho; i++) {
      printf("\t%d - %s - %i\n", i + 1, posicao->nome, posicao->tempo);
      posicao = posicao->proximo;
    }
  }
}

void menu(int *opt) {
  printf("\t1 - Adicionar arquivo\n");
  printf("\t2 - Avancar um segundo\n");
  printf("\t3 - Mostrar fila\n");
  printf("\t0 - Sair\n");
  printf("> ");

  scanf("%i", opt);
  limpar_buffer();
}

int main() {
  int opt, tempo_gasto;
  fila_t fila;

  tempo_gasto = 0;
  iniciar_fila(&fila);

  do {
    limpar_tela();

    menu(&opt);

    switch (opt) {
      case 0:
        break;
      case 1:
        adicionar(&fila);
        break;
      case 2:
        avancar(&fila, &tempo_gasto);
        break;
      case 3:
        mostrar(&fila);
        break;
      default:
        printf("\n\n\tOpcao invalida!\n\n");
    }

    if (opt != 0) {
      printf("\n\n\tEnter para continuar. ");
      limpar_buffer();
    }

  } while (opt != 0);

  printf("\n\n\tTotal de tempo gasto: %i segundos\n\n", tempo_gasto);

  return 0;
}
