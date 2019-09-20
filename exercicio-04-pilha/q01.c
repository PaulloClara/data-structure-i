/*
  Feito/Testado em LINUX!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXDISCS 5
#define UPLINE "\033[A"
#define FIRSTLINE "\033[H"

struct stack {
  int last;
  size_t elements[MAXDISCS];
};

struct stack pinA;
struct stack pinB;
struct stack pinC;

char selectedpin, targetpin;
size_t numberdiscs;

void clear_buffer() {
  char ch;

  while((ch = fgetc(stdin)) != EOF && ch != '\n' ) continue;
}

void clear_screen() {
  system("clear");
}


void init() {  
  clear_screen();
  printf("\n\tQuantidade de discos: ");
  scanf("%d", &numberdiscs);
  clear_buffer();

  if (numberdiscs > MAXDISCS) numberdiscs = MAXDISCS;
  else if (numberdiscs < 3) numberdiscs = 3;

  pinA.last = -1;
  pinB.last = -1;
  pinC.last = -1;

  for (size_t i = 0; i < numberdiscs; i++) {
    pinA.last++;
    pinA.elements[i] = numberdiscs - i;
  }
}

void render_disc(char pin, size_t sizedisc) {
  size_t numbertabs = 1;

  if (pin == 'b') numbertabs = numberdiscs + 1;
  if (pin == 'c') numbertabs = numberdiscs + numberdiscs + 1;
  
  for (size_t i = 0; i < numbertabs; i++) printf("\t");
  for (size_t i = sizedisc; i < numberdiscs; i++) printf("   ");
  for (size_t i = 0; i < sizedisc; i++) printf("██████");
  for (size_t i = sizedisc; i < numberdiscs; i++) printf("   ");

  printf("\n");
}

void show_pins() {
  for (size_t i = 0; i < 9; i++) printf("\n");
  for (int i = pinA.last; i >= 0; i--) render_disc('a', pinA.elements[i]);

  for (int i = 0; i < (pinB.last+1); i++) printf("%s", UPLINE);
  for (int i = pinB.last; i >= 0; i--) render_disc('b', pinB.elements[i]);

  for (int i = 0; i < (pinC.last+1); i++) printf("%s", UPLINE);
  for (int i = pinC.last; i >= 0; i--) render_disc('c', pinC.elements[i]);
}

size_t validate_input() {
  if (selectedpin == targetpin) return 0;
  if (selectedpin != 'a' && selectedpin != 'b' && selectedpin != 'c') return 0;
  if (targetpin != 'a' && targetpin != 'b' && targetpin != 'c') return 0;

  return 1;
}

void treat_input(char *user_input) {
  selectedpin = ' ';
  targetpin = ' ';

  for (size_t i = 0; i < strlen(user_input); i++) {
    if (user_input[i] != ' ') {
      if (selectedpin == ' ') selectedpin = user_input[i];
      else if (targetpin == ' ') targetpin = user_input[i]; 
    }
  }
}

size_t consult_top(char pin) {
  if (pin == 'a') return pinA.elements[pinA.last];
  if (pin == 'b') return pinB.elements[pinB.last];
  if (pin == 'c') return pinC.elements[pinC.last];
}

size_t empty_check(char pin) {
  if (pin == 'a') return (pinA.last >= 0) ? 0 : 1;
  if (pin == 'b') return (pinB.last >= 0) ? 0 : 1;
  if (pin == 'c') return (pinC.last >= 0) ? 0 : 1;
}

size_t validate_changes() {
  if (empty_check(selectedpin)) return 0;
  if (empty_check(targetpin)) return 1;
  if (consult_top(targetpin) > consult_top(selectedpin)) return 1;

  return 0;
}

int pop(char pin) {
  if (pin == 'a') return pinA.elements[pinA.last--];
  if (pin == 'b') return pinB.elements[pinB.last--];
  if (pin == 'c') return pinC.elements[pinC.last--];
}

void push(char pin, size_t disc) {
  if (pin == 'a') pinA.elements[++pinA.last] = disc;
  if (pin == 'b') pinB.elements[++pinB.last] = disc;
  if (pin == 'c') pinC.elements[++pinC.last] = disc;
}

void apply_changes() {
  size_t disc = pop(selectedpin);
  push(targetpin, disc);
}

size_t check_victory() {
  return pinC.last == numberdiscs-1 ? 1 : 0; 
}

int main() {
  char user_input[10];

  init();

  printf("\n\tPara sair => \"exit\"\n");
  printf("\tPinos disponiveis => a b c\n");
  printf("\tEntrada => pino com o disco, pino alvo\n");
  printf("\tExemplo => \"ab\"\n");

  printf("\n\tPressione enter para começar. ");
  clear_buffer();
  clear_screen();

  do {
    show_pins();
  
    printf("%s> ", FIRSTLINE);
    fgets(user_input, 10, stdin);

    if (strcmp(user_input, "exit\n") == 0) break;

    treat_input(user_input);

    if (!validate_input()) {
      printf("\n\t\tEntrada invalida!\n");
      printf("\n\tPressione enter para continuar. ");
      clear_buffer();
      clear_screen();
      continue;
    }

    if (!validate_changes()) {
      printf("\n\t\tMovimento invalido!\n");
      printf("\n\tPressione enter para continuar. ");
      clear_buffer();
      clear_screen();
      continue;
    }

    apply_changes();

    if (check_victory()) {
      clear_screen();
      show_pins();
      printf("\n\t\tPika das galaxias detected!\n");
      printf("\n\t\tPressione enter para sair. ");
      clear_buffer();
      clear_screen();
      break;
    };

    clear_screen();
  } while (1);

  return 0;
}
