/*
  Feito e testado no LINUX!
*/


#include "stdio.h"
#include "stdlib.h"

#define TRUE 1
#define FALSE 0
#define TAM 100

typedef struct {
  int inicio, fim;
  int elementos[TAM];
} lista_t;

void limpar_buffer() {
  char ch;
  while((ch = fgetc(stdin)) != EOF && ch != '\n' ) continue;
}

void limpar_tela() {
  system("clear");
}

void pausar() {
  printf("\n\n\tEnter para continuar. ");
  limpar_buffer();
}

void mostrar_erro(char *erro) {
  printf("\n\t\033[1;93m> %s <\033[0;0m\n", erro);
}

void inicializar(lista_t *lista) {
  lista->fim = 0;
  lista->inicio = 0;
  for (int i = 0; i < TAM; i++) lista->elementos[i] = -1;
}

int tamanho(lista_t *lista) {
  return lista->fim - lista->inicio;
}

int lista_cheia(lista_t *lista) {
  return tamanho(lista) >= TAM - 1 ? TRUE : FALSE;
}

int lista_vazia(lista_t *lista) {
  return tamanho(lista) <= 0 ? TRUE : FALSE;
}

int obter_elemento() {
  int elemento;

  limpar_tela();
  printf("\n\tElemento: ");
  scanf("%i", &elemento);
  limpar_buffer();

  return elemento;
}

size_t obter_index() {
  size_t index;

  limpar_tela();
  printf("\n\tIndex: ");
  scanf("%zu", &index);
  limpar_buffer();

  return index;
}

void inserir(lista_t *lista, int elemento) {
  if (lista_cheia(lista)) return mostrar_erro("Lista cheia!");
  if (lista_vazia(lista)) {
    lista->elementos[lista->fim++] = elemento;
    return;
  }

  for (size_t i = 0; i <= tamanho(lista); i++) {
    if (lista->elementos[i] <= elemento && lista->elementos[i] != -1) continue;

    for (size_t j = tamanho(lista); j > i; j--)
      lista->elementos[j] = lista->elementos[j - 1];

    lista->elementos[i] = elemento;

    break;
  }

  lista->fim++;
}

void remover(lista_t *lista, size_t index) {
  if (lista_vazia(lista)) return mostrar_erro("Lista vazia!");

  if (index < 0 || index >= tamanho(lista))
    return mostrar_erro("Index invalido!");

  for (size_t i = index; i < tamanho(lista); i++)
    lista->elementos[i] = lista->elementos[i + 1];

  lista->fim--;
}

void esvaziar(lista_t *lista) {
  if (lista_vazia(lista)) return mostrar_erro("Lista vazia!");
  inicializar(lista);
}

int buscar(lista_t *lista, size_t index) {
  if (index >= tamanho(lista)) {
    mostrar_erro("Index invalido!");
    return -1;
  }

  return lista->elementos[index];
}

int buscar_primeiro(lista_t *lista) {
  if (lista_vazia(lista)) {
    mostrar_erro("Lista vazia!");
    return -1;
  }

  return lista->elementos[lista->inicio];
}

int buscar_ultimo(lista_t *lista) {
  if (lista_vazia(lista)) {
    mostrar_erro("Lista vazia!");
    return -1;
  }

  return lista->elementos[lista->fim - 1];
}

int buscar_proximo(lista_t *lista) {
  if (lista_cheia(lista)) {
    mostrar_erro("Fim da lista!");
    return -1;
  }

  return lista->elementos[lista->fim];
}

int buscar_anterior(lista_t *lista) {
  if (tamanho(lista) < 2) {
    mostrar_erro("Inicio da lista!");
    return -1;
  }

  return lista->elementos[lista->fim - 2];
}

void status(lista_t *lista) {
  limpar_tela();
  if (lista_vazia(lista)) printf("\n\tLista Vazia\n");
  else if (lista_cheia(lista)) printf("\n\tLista Cheia\n");
  else printf("\n\t%d vagas\n", TAM - tamanho(lista));
}

void mostrar_elemento(char *msg, int elemento) {
  if (elemento == -1) return;
  limpar_tela();
  printf("\n\t%s: %i\n", msg, elemento);
}

void mostrar_lista(lista_t *lista) {
  if (lista_vazia(lista)) return mostrar_erro("Lista vazia!");

  printf("\n\tLista: [");
  for (size_t i = 0; i < tamanho(lista); i++) {
    printf("%d, ", lista->elementos[i]);
  }
  printf("\b\b]\n");
}

void menu(size_t *op) {
  printf("\n\tMenu:\n");
  printf("\t\t1 - Inserir\n");
  printf("\t\t2 - Remover\n");
  printf("\t\t3 - Buscar\n");
  printf("\t\t4 - Esvaziar\n");
  printf("\t\t5 - Mostrar Lista\n");
  printf("\t\t6 - Mostrar Status\n");
  printf("\t\t7 - Mostrar Tamanho\n");
  printf("\t\t8 - Mostrar Primeiro\n");
  printf("\t\t9 - Mostrar Ultimo\n");
  printf("\t\t10 - Mostrar Proximo\n");
  printf("\t\t11 - Mostrar Alterior\n");
  printf("\t\t0 - Sair\n");

  printf("> ");
  scanf("%zu", op);
  limpar_buffer();
}

int main() {
  size_t op;
  lista_t lista;

  inicializar(&lista);

  do {
    menu(&op);

    switch (op) {
      case 0:
        limpar_tela();
        break;
      case 1:
        inserir(&lista, obter_elemento());
        break;
      case 2:
        remover(&lista, obter_index());
        break;
      case 3:
        mostrar_elemento("Elemento", buscar(&lista, obter_index()));
        break;
      case 4:
        esvaziar(&lista);
        break;
      case 5:
        mostrar_lista(&lista);
        break;
      case 6:
        status(&lista);
        break;
      case 7:
        mostrar_elemento("Tamanho", tamanho(&lista));
        break;
      case 8:
        mostrar_elemento("Primeiro", buscar_primeiro(&lista));
        break;
      case 9:
        mostrar_elemento("Ultimo", buscar_ultimo(&lista));
        break;
      case 10:
        mostrar_elemento("Proximo", buscar_proximo(&lista));
        break;
      case 11:
        mostrar_elemento("Anterior", buscar_anterior(&lista));
        break;
      default:
        mostrar_erro("Opcao invalida");
        break;
    }

    if (op != 0) pausar();
    limpar_tela();
  } while(op != 0);

  return 0;
}
