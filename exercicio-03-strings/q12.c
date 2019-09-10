#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

size_t getLen(char *vector) {
  size_t len = 0;

  do {
    continue;
  } while(vector[len++] != '\0' && vector[len++] != '\n');

  return len;
}

size_t checkVowel(char ch) {
  switch (ch) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
      return 1;
    default:
      return 0;
  }
}

size_t rmvChar(char *str, char ch, size_t len) {
  size_t newlen = len;

  for (size_t i = 0; i < len; i++) {
    if (str[i] == ch) {
      for (size_t j = i; j < newlen; j++) {
        str[j] = str[j+1];
      }
      newlen--;
    }
  }
  str[newlen] = '\0';

  return newlen;
}

void copyStr(char *stringO, char *stringD) {
  size_t len = 0;

  while (stringO[len] != '\0' && stringO[len] != '\n') {
    stringD[len] = stringO[len];
    len++;
  }
  stringO[len] = '\0';
}

size_t mergeStrs(char *str1, char *str2, char ch) {
  // str1 é usado como "base" para receber str2, ch é ignorado na str2
  size_t istr1 = 0;
  size_t newlen = 0;

  char strtemp[getLen(str1)+getLen(str2)];

  for (size_t i = 0; i < getLen(str2); i++) {
    if (str2[i] == ch) {
      strtemp[newlen++] = str1[istr1++];
    } else {
      strtemp[newlen++] = str2[i];
    }
  }
  strtemp[newlen--] = '\0';

  copyStr(strtemp, str1);

  return newlen;
}

int main() {
  char password[MAXLEN];
  size_t len_password;

  char charsRmv[] = "aeiouAEIOU";

  fprintf(stdout, "\t> Digite a senha <\n> ");
  fgets(password, MAXLEN, stdin);
  password[strlen(password)-1] = 0;
  len_password = strlen(password);

  fprintf(stdout, "\n\n\tSenha antes => %s\n", password);

  char key[len_password];

  size_t i_temp = 0;
  for (size_t i = 0; i < len_password; i++) {
    key[i] = '*';
    if (checkVowel(password[i])) key[i] = password[i];
    else i_temp++;
  }
  key[len_password] = 0;

  for (size_t i = 0; i < 10; i++) {
    rmvChar(password, charsRmv[i], strlen(password));
  }

  fprintf(stdout, "\tSenha processada %s\n", password);
  fprintf(stdout, "\tChave %s\n", key);

  mergeStrs(password, key, '*');

  fprintf(stdout, "\tSenha depois %s\n", password);

  return 0;
}
