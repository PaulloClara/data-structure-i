/*
*******************************************************************

Finalidade: Implementar uma pilha dinamica
Operacoes:
          - Empilhar (PUSH)
          - Desempilhar (POP)
          - Mostrar pilha
          - Topo da pilha
          - Tamanho da pilha
          - Inicializacao da pilha
          - Esvaziar pilha
         
******************************************************************* 
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct no {
  int elemento;
  no *proximo;
};

struct pilha {
  int tamanho;
  no *topo;
};

pilha p1, p2, p3;

void inicializacao (pilha *p) {
  p->topo = NULL;
  p->tamanho = 0;
}

bool pilhaVazia(pilha *p) {
  return (p->topo == NULL);
}

void tamanho (pilha *p) {
  if (pilhaVazia(p)) {
    printf("\n\nPilha vazia\n");                              
  }
  else {
    printf("\n\nTamanho : %i\n", p->tamanho);   
  }
}

void _topo (pilha *p) {
  no *ptr;
  
  if (pilhaVazia(p)) {
    printf("\n\nPilha vazia\n");
  }
  else {
    ptr = p->topo;
    printf("\n\nTopo: %i", ptr->elemento);     
  }
}

void empilhar (pilha *p, int e) {
  no *ptr;

  ptr = (no*) malloc(sizeof(no));
  if (ptr == NULL) {      // Teste de alocação
    printf("\n\nNão foi possível alocar memória!\n");
  } else {
    ptr->elemento = e;
    ptr->proximo = p->topo;
    p->topo = ptr;
    p->tamanho = p->tamanho + 1;          
  }
}
   
int desempilhar (pilha *p) {
  no *ptr;
  int e;
  
  ptr = p->topo;
  p->topo = ptr->proximo;
  p->tamanho = p->tamanho - 1;
  e = ptr->elemento;     
  free(ptr);
  ptr = NULL;

  return e;
}

void mostrarPilha (pilha *p){
   
  no *ptr;

  if (pilhaVazia(p)) {
    printf("\n\nPilha vazia\n");
  }
  else {
    printf("\n");     	
    ptr = p->topo;
    do {
      printf("\nElemento: %i", ptr->elemento);
      ptr = ptr->proximo;
    } while ( ptr != NULL );
  }
}

void esvaziarPilha (pilha *p) {
  int e;

  if (pilhaVazia(p)) {
    printf("\n\nPilha vazia\n");
  }
  else {
    printf("\n\nEsvaziando pilha ...\n");     	
    while (!pilhaVazia(p)) {
      e = desempilhar(p);
      printf("\nElemento desempilhado : %i", e);                
    }
    printf("\n\nPilha esvaziada\n");
  } 
}

void menu() {

  char opcao;
  int e;
  
  inicializacao(&p1); // para usar a pilha p2, basta chamar "inicializacao(&p2);"
  
  do {
    system("cls");
    printf("PILHA DINAMICA\n\n" );      
    printf("1 - Empilhar\n");
    printf("2 - Desempilhar\n");         
    printf("3 - Mostrar pilha\n");
    printf("4 - Topo da pilha\n");
    printf("5 - Tamanho da pilha\n");      
    printf("6 - Esvaziar pilha\n");             
    printf("0 - Sair\n\n");   
    printf("Opcao: ");   
    opcao = getche();

    switch (opcao) {
      case '1' : {
        printf("\n\nElemento : ");
        scanf("%i", &e);
        empilhar(&p1, e);
        break;
      }
      case '2' : {
        if (pilhaVazia(&p1)) {
          printf("\n\nPilha vazia\n");               
        } else {                    
          e = desempilhar(&p1);
          printf("\n\nElemento desempilhado: %i", e);
        }
        break;
      }
      case '3' : {
        mostrarPilha(&p1);
        break;
      }
      case '4' : {
        _topo(&p1);
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
    }
    getch();
  
  }
  while (opcao != '0');

}

// programa principal
int main() {

  menu();

  return 0;
}
// fim do programa 

