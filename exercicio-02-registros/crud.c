#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXALUNOS 100
#define MAXNOTAS 1000

#define MAXNOME 50
#define MAXMATRICULA 7
#define MAXDICIPLINA 9
#define MAXENDERECO 40

struct Aluno {
  char matricula[MAXMATRICULA];
  char nome[MAXNOME];
  char nascimento[11];
  char endereco[MAXENDERECO];
};

struct Nota {
  char matricula[MAXMATRICULA];
  char diciplina[MAXDICIPLINA];
  float nota1;
  float nota2;
  float nota3;
};

struct Aluno alunos[MAXALUNOS];
struct Nota notas[MAXNOTAS], notatemp;
size_t indexaluno, indexnota, opcao = 0;

struct Aluno alunotemp;
struct Nota notatemp;

int matricula_existe;

void limpar_sujeira() {
  char ch;

  while((ch = fgetc(stdin)) != EOF && ch != '\n' ) {
    continue;
  }
}

void menu() {
  do {
    printf("\n\n");
    printf("\t1 - Add Aluno\n");
    printf("\t2 - Add Nota\n");
    printf("\t3 - Mostrar aluno(s)\n");
    printf("\t4 - Mostrar nota(s)\n");
    printf("\t0 - Sair\n> ");

    scanf("%d", &opcao);
    limpar_sujeira();

    if (opcao > 4) printf("\tOpcao invalida!\n");
  } while (opcao > 4);
}

void menu_add_notas() {
  do {
    printf("\n\n");
    printf("\t1 - Add Primeira nota\n");
    printf("\t2 - Add Segunda nota\n");
    printf("\t3 - Add Terceira nota\n");
    printf("\t0 - Voltar\n> ");

    scanf("%d", &opcao);
    limpar_sujeira();

    if (opcao > 3) printf("\tOpcao invalida!\n");
  } while (opcao > 3);
}

void menu_notas() {
  do {
    printf("\n\n");
    printf("\t1 - Mostrar todas as notas\n");
    printf("\t2 - Buscar por matricula\n");
    printf("\t0 - Voltar\n> ");

    scanf("%d", &opcao);
    limpar_sujeira();

    if (opcao > 2) printf("\tOpcao invalida!\n");
  } while (opcao > 2);
}

void menu_alunos() {
  do {
    printf("\n\n");
    printf("\t1 - Mostrar todos os alunos\n");
    printf("\t2 - Buscar por matricula\n");
    printf("\t0 - Voltar\n> ");

    scanf("%d", &opcao);
    limpar_sujeira();

    if (opcao > 2) printf("\tOpcao invalida!\n");
  } while (opcao > 2);
}

void center_print(const char *s, int width) {
  int length = strlen(s);
  int i;
  for (i=0; i<=(width-length)/2; i++) fputs(" ", stdout);
  fputs(s, stdout);
  i += length;
  for (; i<=width; i++) fputs(" ", stdout);
}

void mostrar_dados_do_aluno(size_t index, size_t mostrar_cabecalho) {
  if (mostrar_cabecalho == 1) {
    printf("\n\n\n");
    printf("\t--------------------------------------------------------------------------------\n");
    printf("\t| MATRICULA |            NOME            | NASCIMENTO |        ENDEREÇO        |\n");
    printf("\t--------------------------------------------------------------------------------\n");
  }
  printf("\t|"); center_print(alunos[index].matricula, 10);
  printf("|"); center_print(alunos[index].nome, 27);
  printf("|"); center_print(alunos[index].nascimento, 11);
  printf("|"); center_print(alunos[index].endereco, 23); printf("|");
  printf("\n\t--------------------------------------------------------------------------------\n");
}

void mostrar_notas_do_aluno(size_t index, size_t mostrar_cabecalho) {
  if (mostrar_cabecalho == 1) {
    printf("\n\n\n");
    printf("\t-------------------------------------------------------------\n");
    printf("\t| MATRICULA |     DICIPLINA      | NOTA 1 | NOTA 2 | NOTA 3 |\n");
    printf("\t-------------------------------------------------------------\n");
  }
  printf("\t|"); center_print(notas[index].matricula, 10);
  printf("|"); center_print(notas[index].diciplina, 19);
  printf("|  %2.2f  ", notas[index].nota1);
  printf("|  %2.2f  ", notas[index].nota2);
  printf("|  %2.2f  |", notas[index].nota3);
  printf("\n\t-------------------------------------------------------------\n");
}

int procurar_aluno(char *matricula) {
  for (int i = 0; i < indexaluno; i++) {
    if (strcmp(alunos[i].matricula, matricula) == 0) return i;
  }

  return -1;
}

void mostrar_alunos() {
  char matricula[MAXMATRICULA];
  int index_do_aluno = -1;

  menu_alunos();
  switch (opcao) {
    case 1:
      for (size_t i = 0; i < indexaluno; i++) mostrar_dados_do_aluno(i, i+1);
      break;
    case 2:
      do {
        printf("\nMatricula do aluno (0 para voltar): ");
        scanf("%s", matricula);
        limpar_sujeira();

        if (matricula[0] == '0') break;

        index_do_aluno = procurar_aluno(matricula);
        if (index_do_aluno < 0) printf("\tMatricula invalida!\n\n");
      } while(index_do_aluno < 0);
      if (index_do_aluno >= 0) mostrar_dados_do_aluno(index_do_aluno, 1);
      break;
  }
}

void mostrar_notas() {
  char matricula[MAXMATRICULA];
  int index_do_aluno = -1;

  menu_notas();
  switch (opcao) {
    case 1:
      for (size_t i = 0; i < indexnota; i++) mostrar_notas_do_aluno(i, i+1);
      break;
    case 2:
      do {
        printf("\nMatricula do aluno (0 para voltar): ");
        scanf("%s", matricula);
        limpar_sujeira();

        if (matricula[0] == '0') return;

        index_do_aluno = procurar_aluno(matricula);
        if (index_do_aluno < 0) printf("\tMatricula invalida!\n\n");
      } while(index_do_aluno < 0);
      mostrar_notas_do_aluno(index_do_aluno, 1);
      break;
  }
}

void add_aluno() {
  do {
    printf("\n\nMatricula do aluno (0 para voltar): ");
    scanf("%s", alunotemp.matricula);
    limpar_sujeira();

    if (alunotemp.matricula[0] == '0') return;

    matricula_existe = (procurar_aluno(alunotemp.matricula) >= 0) ? 1 : 0;

    if (matricula_existe) printf("\tMatricula invalida!\n");
  } while (matricula_existe);

  printf("Nome do aluno: ");
  fgets(alunotemp.nome, MAXNOME, stdin);
  alunotemp.nome[strlen(alunotemp.nome)-1] = '\0';

  printf("Data de nascimento do aluno: ");
  scanf("%s", alunotemp.nascimento);
  limpar_sujeira();

  printf("Endereço do aluno: ");
  fgets(alunotemp.endereco, MAXENDERECO, stdin);
  alunotemp.endereco[strlen(alunotemp.endereco)-1] = '\0';

  strcpy(alunos[indexaluno].matricula, alunotemp.matricula);
  strcpy(alunos[indexaluno].nome, alunotemp.nome);
  strcpy(alunos[indexaluno].nascimento, alunotemp.nascimento);
  strcpy(alunos[indexaluno].endereco, alunotemp.endereco);
  indexaluno++;
}

void add_nota() {
  do {
    printf("\n\nMatricula do aluno (0 para voltar): ");
    scanf("%s", notatemp.matricula);
    limpar_sujeira();

    if (notatemp.matricula[0] == '0') return;

    matricula_existe = (procurar_aluno(notatemp.matricula) >= 0) ? 1 : 0;

    if (!matricula_existe) printf("\tMatricula invalida!\n");
  } while (!matricula_existe);

  printf("Diciplina: ");
  fgets(notatemp.diciplina, MAXDICIPLINA, stdin);
  notatemp.diciplina[strlen(notatemp.diciplina)-1] = '\0';

  do {
    menu_add_notas();
    switch (opcao) {
      case 1:
        printf("Primeira nota: ");
        scanf("%f", &notatemp.nota1);
        break;
      case 2:
        printf("Segunda nota: ");
        scanf("%f", &notatemp.nota2);
        break;
      case 3:
        printf("Terceira nota: ");
        scanf("%f", &notatemp.nota3);
        break;
    }
  } while (opcao);

  strcpy(notas[indexnota].matricula, notatemp.matricula);
  strcpy(notas[indexnota].diciplina, notatemp.diciplina);
  notas[indexnota].nota1 = notatemp.nota1;
  notas[indexnota].nota2 = notatemp.nota2;
  notas[indexnota].nota3 = notatemp.nota3;
  indexnota++;
  notatemp.nota1 = 0;
  notatemp.nota2 = 0;
  notatemp.nota3 = 0;
}

int main() {
  menu();

  while (opcao) {
    switch (opcao) {
      case 1:
        add_aluno();
        break;
      case 2:
        add_nota();
        break;
      case 3:
        mostrar_alunos();
        break;
      case 4:
        mostrar_notas();
        break;
    }

    menu();
  }

  return 0;
}
