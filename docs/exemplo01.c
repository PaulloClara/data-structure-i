 
/*
*******************************************************************

Finalidade: Implementar uma pilha estatica
Operacoes:
          - Empilhar (PUSH)
          - Desempilhar (POP)
          - Mostrar pilha
          - Consultar topo da pilha
          - Tamanho da pilha
          - Inicializacao da pilha
          - Esvaziar pilha
          - Pilha cheia
          - Pilha vazia

*******************************************************************
*/

#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define tam 5   // tamanho da pilha

typedef struct  {
       int topo;
       char elemento[tam];
} pilha;

pilha p1;

void inicializacao (pilha *p) {

     p->topo = -1;

}

bool pilhaCheia(pilha *p) {

     bool retorno = false;

     if (p->topo == tam - 1) {
        retorno = true;
     }
     return retorno;

}

bool pilhaVazia(pilha *p) {

     bool retorno = false;

     if (p->topo == -1) {
        retorno = true;
     }
     return retorno;

}

void tamanho (pilha *p) {

     if (pilhaVazia(p)) {
        printf("\n\nPilha vazia\n");
     }
     else {
          printf("\n\nTamanho : %i\n", p->topo + 1);
     }

}

void consultarTopo (pilha *p) {

     if (pilhaVazia(p)) {
        printf("\n\nPilha vazia\n");
     }
     else {
          printf("\n\nTopo: %c\n", p->elemento[p->topo]);
     }

}

void mostrarPilha (pilha *p) {

     int i;

     if (pilhaVazia(p)) {
        printf("\n\nPilha vazia\n");
     }
     else {
          printf("\n\nPilha");
          for (i = p->topo; i >= 0; i = i - 1) {
              printf("\n %c", p->elemento[i]);
          }
     }

}

void empilhar (pilha *p, char e) { // push

     p->topo = p->topo + 1;
     p->elemento[p->topo] = e;

}

char desempilhar (pilha *p) { // pop

     char e;

     e = p->elemento[p->topo];
     p->topo = p->topo - 1;

     return e;

}

void esvaziarPilha (pilha *p) {

     char e;

     if (pilhaVazia(p)) {
        printf("\n\nPilha vazia\n");
     }
     else {
          printf("\n\nEsvaziando pilha ...\n");
          while (!pilhaVazia(p)) {
                e = desempilhar(p);
                printf("\nElemento desempilhado: %c", e);
          }
          printf("\n\nPilha esvaziada\n");
     }

}

void menu() {

     char opcao, e;

     inicializacao(&p1);

     do {
        system("cls");
        printf("PILHA ESTATICA\n\n" );
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Mostrar pilha\n");
        printf("4 - Consultar topo da pilha\n");
        printf("5 - Tamanho da pilha\n");
        printf("6 - Esvaziar pilha\n");
        printf("X - Sair\n\n");
        printf("Opcao: ");
        opcao = toupper(getche());
        switch (opcao) {
               case '1' : {
                    if (pilhaCheia(&p1)) {
                       printf("\n\nPilha cheia\n");
                    }
                    else {
                         printf("\n\nElemento: ");
                         e = getche();
                         empilhar(&p1, e);
                    }
                    break;
               }
               case '2' : {
                    if (pilhaVazia(&p1)) {
                       printf("\n\nPilha vazia\n");
                    }
                    else {
                         e = desempilhar(&p1);
                         printf("\nElemento desempilhado: %c", e);
                    }
                    break;
               }
               case '3' : {
                    mostrarPilha(&p1);
                    break;
               }
               case '4' : {
                    consultarTopo(&p1);
                    break;
               }
               case '5' : {
                    tamanho(&p1);
                    break;
               }
               case '6' : {
                    esvaziarPilha(&p1);
                    break;
               }
               case 'X' : {
                    printf("\n\nSaindo ...");
                    break;
               }
               default  : {
                        printf("\n\nOpcao invalida");
               }
        }
        printf("\n\n");
        system("pause");
   }
   while (opcao != 'X');

}

int main() { // programa principal

    menu();

}
// fim do programa

