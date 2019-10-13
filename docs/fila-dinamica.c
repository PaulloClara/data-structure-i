/*
*******************************************************************

Finalidade: Implementar uma fila dinamica
Operacoes:
          - Entrar
          - Sair
          - Mostrar fila
          - Inicio da fila
          - Fim da fila
          - Tamanho da fila
          - Inicializacao da fila
          - Esvaziar fila
          - fila vazia

*******************************************************************
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct no {
       int elemento;
       no *proximo;
};

struct fila {
  int tamanho;
  no *inicio, *fim;
};

fila f1;

void inicializacao (fila *f) {

  f->inicio = NULL;
  f->fim = NULL;
  f->tamanho = 0;

}

bool filaVazia (fila *f) {

  return (f->tamanho == 0);

}

void tamanho (fila *f) {

  if (filaVazia(f)) {
    printf("\n\nFila vazia\n");
  }
  else {
      printf("\n\nTamanho : %i\n", f->tamanho);
  }
}

void consultarInicio (fila *f) {

  no *ptr;

  if (filaVazia(f)) {
    printf("\n\nFila vazia\n");
  }
  else {
    ptr = f->inicio;
    printf("\n\nInicio: %i", ptr->elemento);
  }
}

void consultarFim (fila *f) {

  no *ptr;

  if (filaVazia(f)) {
    printf("\n\nFila vazia\n");
  }
  else {
    ptr = f->fim;
    printf("\n\nFim: %i", ptr->elemento);
  }
}

void entrar (fila *f, int e) {

     no *ptr;

     ptr = (no*) malloc(sizeof(no));
     if (ptr == NULL) {      // Teste de alocação
        printf("\n\nNão foi possível alocar memória!\n");
     }
     else {
          ptr->elemento = e;
          ptr->proximo = NULL;
          if (filaVazia(f)) { // insercao do primeiro elemento
             f->inicio = ptr;
             f->fim = ptr;
          }
          else {
               f->fim->proximo = ptr;
               f->fim = ptr;
          }
          f->tamanho = f->tamanho + 1;
     }

}

int sair (fila *f) {

     no *ptr;
     int e;

     if (f->inicio == f->fim) {
        f->fim = NULL;
     }
     ptr = f->inicio;
     e = ptr->elemento;
     f->inicio = f->inicio->proximo;
     f->tamanho = f->tamanho - 1;
     free(ptr);
//     ptr = NULL;

     return e;
}

void mostrarFila (fila *f){

     no *ptr;

     if (filaVazia(f)) {
        printf("\n\nFila vazia\n");
     }
     else {
          printf("\n\nFila: ");
          ptr = f->inicio;
          do {
             printf("%i ", ptr->elemento);
             ptr = ptr->proximo;
          } while ( ptr != NULL );
     }
}

void esvaziarFila (fila *f) {

     int e;

     if (filaVazia(f)) {
        printf("\n\nFila vazia\n");
     }
     else {
          printf("\n\nEsvaziando Fila\n\n");
          while (!filaVazia(f)) {
                e = sair(f);
                printf("Saindo elemento: %i\n", e);
          }
          printf("\n\nFila esvaziada\n");
     }
}

void menu() {

    char opcao;
    int e;

    inicializacao(&f1);

    do {
       system("cls");
       printf("FILA DINAMICA\n\n" );
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
                   printf("\n\nElemento : ");
                   scanf("%i", &e);
                   entrar(&f1, e);
                   break;
              }
              case '2' : {
              		if (filaVazia(&f1)) {
						printf("\n\nFila Vazia\n");
					}
					else {
                   	   e = sair(&f1);
                       printf("\n\nElemento removido: %i", e);
                    }
                   break;
              }
              case '3' : {
                   mostrarFila(&f1);
                   break;
              }
              case '4' : {
                   consultarInicio(&f1);
                   break;
              }
              case '5' : {
                   consultarFim(&f1);
                   break;
              }
              case '6' : {
                   tamanho(&f1);
                   break;
              }
              case '7' : {
                   esvaziarFila(&f1);
                   break;
              }
       }
       getch();
    }
    while (opcao != '0');

}

// programa principal
int main() {

    menu();

}
// fim do programa
