/*
  Feito e testado no Linux!
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 20

typedef struct {
  int senha;
  int hora_entrada;
  int tempo_necessario;
  int hora_saida;
} cliente_t;

typedef struct {
  cliente_t clientes[TAM];
  int inicio;
  int fim;
} fila_t;

typedef struct {
  fila_t clientes_atendidos;
  char status;  // l == livre, o == ocupado
} guiche_t;

void limpar_buffer() {
  char ch;
  while((ch = fgetc(stdin)) != EOF && ch != '\n' ) continue;
}

void limpar_tela() {
  system("clear");
}

int obter_valor_randomico() {
  int valor = 0;

  do {
    valor = rand() % 1000;
  } while (valor > 600 || valor < 60);

  return valor / 60;
}

void iniciar_fila(fila_t *fila) {
  fila->inicio = -1;
  fila->fim = -1;
}

void iniciar_guiche(guiche_t *guiche) {
  guiche->status = 'l';
  iniciar_fila(&guiche->clientes_atendidos);
}

int fila_vazia(fila_t *fila) {
  if (fila->inicio < 0) return 1;
  return 0;
}

int fila_cheia(fila_t *fila) {
  if (fila->fim == TAM - 1) return 1;
  return 0;
}

void mostrar_msg(char *msg) {
  printf("\n\t%s\n\n", msg);
  printf("\n\tEnter para continuar. ");
  limpar_buffer();
  limpar_tela();
}

void mostrar_fila(fila_t *fila) {
  printf("\n\n\t Senha | Chegada\n");
  for (size_t i = fila->inicio; i < fila->fim + 1; i++) {
    printf("\t %3d   |   ", fila->clientes[i].senha);
    printf("%2d\n", fila->clientes[i].hora_entrada);
  }
}

void mostrar_guiche(guiche_t *guiche, char letra) {
  int index = guiche->clientes_atendidos.fim;

  if (letra == 'A') {
    printf("\t------------------------------------------\n");
    printf("\t|\t   | Status | Senha | Tempo Nec. |\n");
  }
  printf("\t------------------------------------------\n");
  
  printf("\t| Guiche %c:", letra);
  if (guiche->status == 'l') printf("  Livre  |  ...  |     ...    |\n");
  else {
    printf(" Ocupado | %3d   |    %3d     |\n",
      guiche->clientes_atendidos.clientes[index].senha,
      guiche->clientes_atendidos.clientes[index].tempo_necessario
    );
  }

  if (letra == 'C') printf("\t------------------------------------------\n");
}

int entrar(fila_t *fila, int hora_atual, int total_pessoas) {
  if (fila_cheia(fila)) return 1;

  cliente_t cliente;

  if (fila_vazia(fila)) fila->inicio++;

  fila->fim++;

  cliente.senha = total_pessoas + 1;
  cliente.hora_entrada = hora_atual;
  cliente.tempo_necessario = obter_valor_randomico();
  
  fila->clientes[fila->fim] = cliente;

  return 0;
}

int remover(fila_t *fila) {
  if (fila_vazia(fila)) return 1;

  if (fila->inicio == fila->fim) {
    fila->inicio = -1;
    fila->fim = -1;
  } else fila->inicio++;

  return 0;
}

void contar_atendimento(guiche_t *guiche) {
  int index = guiche->clientes_atendidos.fim;

  guiche->clientes_atendidos.clientes[index].tempo_necessario--;

  if (guiche->clientes_atendidos.clientes[index].tempo_necessario == 0) {
    guiche->status = 'l';
  }
}

void atender(guiche_t *guiche, fila_t *fila, int hora_atual) {
  int index;

  if (fila_vazia(fila)) return;

  guiche->clientes_atendidos.fim++;
  index = guiche->clientes_atendidos.fim;

  guiche->clientes_atendidos.clientes[index] = fila->clientes[fila->inicio];
  guiche->clientes_atendidos.clientes[index].hora_saida = hora_atual;
  guiche->status = 'o';

  remover(fila);
}

void avancar(fila_t *fila, guiche_t *a, guiche_t *b, guiche_t *c, int hora_atual) {
  if (a->status == 'l') atender(a, fila, hora_atual);
  else contar_atendimento(a);

  if (b->status == 'l') atender(b, fila, hora_atual);
  else contar_atendimento(b);

  if (c->status == 'l') atender(c, fila, hora_atual);
  else contar_atendimento(c);
}

void mostrar_resultado(guiche_t *guiche, char letra) {
  int total_espera, media_espera;

  total_espera = 0;

  for (int i = 0; i < guiche->clientes_atendidos.fim + 1; i++) {
    total_espera += guiche->clientes_atendidos.clientes[i].hora_saida;
    total_espera -= guiche->clientes_atendidos.clientes[i].hora_entrada;
  }

  if (guiche->clientes_atendidos.fim <= 0) media_espera = 0;
  else media_espera = total_espera / (guiche->clientes_atendidos.fim + 1);

  printf("\tGuiche %c => ", letra);
  printf("|  %3d    |     %4d     |       %3d       |\n",
    guiche->clientes_atendidos.fim + 1,
    total_espera,
    media_espera
  );
}

void rodar(guiche_t *a, guiche_t *b, guiche_t *c, fila_t *fl, int tp, int ha) {
  int total_espera, media_espera;

  while (a->status == 'o' || b->status == 'o' || c->status == 'o' || !fila_vazia(fl)) {
    avancar(fl, a, b, c, ha);
    ha++;
  }

  printf("\t\t    | Atendeu | Total Espera | Media de Espera |\n");

  mostrar_resultado(a, 'A');
  mostrar_resultado(b, 'B');
  mostrar_resultado(c, 'C');

  printf("\n\n\n");
}

void menu(int *op) {
  printf("\t1 - Entrar na fila\n");
  printf("\t2 - Mostrar Status\n");
  printf("\t3 - Avancar um minuto\n");
  printf("\t4 - Rodar simulacao\n");
  printf("\t0 - Sair\n> ");

  scanf("%i", op);
  limpar_buffer();
}

int main() {
  int op, hora_atual, total_pessoas;
  hora_atual = 0;
  total_pessoas = 0;

  guiche_t guiche_a, guiche_b, guiche_c;
  fila_t fila;

  iniciar_guiche(&guiche_a);
  iniciar_guiche(&guiche_b);
  iniciar_guiche(&guiche_c);

  iniciar_fila(&fila);

  srand(time(NULL));

  do {
    menu(&op);

    switch (op) {
      case 0:
        break;
      case 1:
        if (entrar(&fila, hora_atual, total_pessoas)) mostrar_msg("Fila cheia!");
        else {
          total_pessoas++;
          mostrar_msg("");
        }
        break;
      case 2:
        mostrar_guiche(&guiche_a, 'A');
        mostrar_guiche(&guiche_b, 'B');
        mostrar_guiche(&guiche_c, 'C');
        if (fila_vazia(&fila)) mostrar_msg("Fila vazia!");
        else {
          mostrar_fila(&fila);
          mostrar_msg("");
        }
        break;
      case 3:
        avancar(&fila, &guiche_a, &guiche_b, &guiche_c, hora_atual);
        hora_atual++;
        mostrar_msg("Um minuto foi avancado com sucesso!");
        break;
      case 4:
        rodar(&guiche_a, &guiche_b, &guiche_c, &fila, total_pessoas, hora_atual);
        op = 0;
        break;
      default:
        mostrar_msg("Essa opcao n existe, vc tem demencia?");
        break;
    }
  } while (op != 0);

  return 0;
}