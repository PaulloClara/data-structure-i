/*
  Feito/Testado no LINUX!

  Funcionamento de acordo com a questao: {
    vazio;
    chega carro A;
    resultado => A;
    chega carro B;
    resultado => AB;
    chega carro C;
    resultado => ABC;
    sai carro B;
    consequencia: sai carro C, sai carro B, volta carro C;
    resultado => A_C;
    chega carro D;
    consequencia: sai carro C, entra carro D, volta carro C;
    resultado => ADC;
    chega carro E;
    resultado => ADCE;
    ...
  }
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAXNAMECAR 40
#define MAXPARKING 4
#define MAXLICENSEPLATE 40

typedef struct typecar {
  size_t space;
  char name[MAXNAMECAR];
  char licenseplate[MAXLICENSEPLATE];
} typecar;

typedef struct typeparking {
  size_t last, current, max;
  size_t map[MAXNAMECAR];
  typecar cars[MAXNAMECAR];
} typeparking;

void clear_buffer() {
  char ch;
  while((ch = fgetc(stdin)) != EOF && ch != '\n' ) continue;
}

void clear_screen() {
  system("clear");
}

void init(typeparking *parking) {
  parking->last = 0;
  parking->current = 0;
  parking->max = MAXPARKING;
  for (size_t i = 0; i < MAXPARKING; i++) parking->map[i] = FALSE;
}

size_t crowded_check(typeparking *parking) {
  return parking->current >= parking->max ? TRUE : FALSE;
}

size_t check_vacant(typeparking *parking) {
  return parking->map[parking->last] == FALSE ? TRUE : FALSE;
}

size_t check_vacant_spaces(typeparking *parking) {
  return parking->last > parking->current ? TRUE : FALSE;
}

size_t check_licenseplate(typeparking *parking, char *licenseplate) {
  if (!strcmp(parking->cars[parking->last].licenseplate, licenseplate))
    return TRUE;
  return FALSE;
}

void check_maneuvers(size_t lastcar, size_t currentcar) {
  size_t maneuvers = 0;

  if (lastcar > currentcar) maneuvers = lastcar - currentcar;

  printf("\n\n\t%d carros foram manobrados!", maneuvers);
  printf("\n\n\tEnter para continuar. ");
  clear_buffer();
}

void error_msg(char *msg) {
  clear_screen();
  printf("\n\t%s\n\n\tEnter para continuar. ", msg);
  clear_buffer();
}

void register_car(typecar *car) {
  printf("carro: "); scanf("%s", car->name);
  printf("placa do carro: "); scanf("%s", car->licenseplate);
}

void push(typeparking *parking) {
  parking->last++;
}

void pop(typeparking *parking) {
  parking->last--;
}

void return_parking(typeparking *parking, size_t lastcar) {
  size_t difference;
  if (lastcar > parking->last) {
    difference = lastcar - parking->last;
    for (size_t i = 0; i < difference; i++) push(parking);
  }
}

void add_car(typeparking *parking) {
  size_t lastcar = parking->last;
  typecar car;

  if (crowded_check(parking)) error_msg("Estacionamento lotado!");
  else {
    register_car(&car);

    if (check_vacant_spaces(parking)) {
      for (size_t i = 0; i < lastcar; i++) {
        pop(parking);
        if (check_vacant(parking)) break;
      }
    }
    
    car.space = parking->last + 1;
    parking->cars[parking->last] = car;
    parking->map[parking->last] = 1;
    parking->current++;
    push(parking);
   
    check_maneuvers(lastcar, parking->last);

    return_parking(parking, lastcar);
  }
}

void remove_car(typeparking *parking) {
  size_t lastcar = parking->last;
  char licenseplate[MAXLICENSEPLATE];

  printf("placa do carro: "); scanf("%s", licenseplate);

  for (size_t i = 0; i < lastcar; i++) {
    pop(parking);
    if (check_licenseplate(parking, licenseplate)) break;
  }

  if (!check_licenseplate(parking, licenseplate)) error_msg("Placa não encontrada!");
  else {
    parking->current--;
    parking->map[parking->last] = 0;

    check_maneuvers(lastcar - 1, parking->last);
  }

  return_parking(parking, lastcar);
}

void center_print(const char *s, int width) {
  size_t length = strlen(s); size_t i = 0;
  for (; i <= (width - length) / 2; i++) fputs(" ", stdout);
  fputs(s, stdout); i += length;
  for (; i <= width; i++) fputs(" ", stdout);
}

void show_car(typecar *car) {
  printf("\t|"); printf(" %3d  ", car->space);
  printf("|"); center_print(car->name, 30);
  printf("|"); center_print(car->licenseplate, 8); printf("|");
  printf("\n\t--------------------------------------------------\n");
}

void show_parking(typeparking *parking) {
  size_t lastcar = parking->last;

  printf("\n\n\n");
  printf("\t--------------------------------------------------\n");
  printf("\t| VAGA |              CARRO            |  PLACA  |\n");
  printf("\t--------------------------------------------------\n");

  for (size_t i = 0; i < lastcar; i++) {
    pop(parking);
    if (!check_vacant(parking)) show_car(&parking->cars[parking->last]);
  }

  for (size_t i = 0; i < lastcar; i++) push(parking);

  printf("\n\tTotal de carros => %d\n\n", parking->current);

  printf("\n\n\tEnter para continuar. ");
  clear_buffer();
}

int main() {
  char option;
  size_t continueloop = TRUE;

  typeparking parking;

  init(&parking);

  do {
    printf("\n\t1 - Novo carro");
    printf("\n\t2 - Tirar carro");
    printf("\n\t3 - Ver registro");
    printf("\n\t0 - Sair");
    printf("\n> ");
    
    option = fgetc(stdin);
    clear_screen();
    switch (option) {
      case '0':
        continueloop = FALSE;
      break;
      case '1':
        add_car(&parking);
      break;
      case '2':
        remove_car(&parking);
      break;
      case '3':
        show_parking(&parking);
      break;
      default:
        error_msg("Valor invalido!");
    }
    clear_buffer();
    clear_screen();
  } while (continueloop);

  return 0;
}