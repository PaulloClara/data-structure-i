#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

void slice(char *stro, char *strd, size_t start, size_t end) { /* q10 */
  size_t len = 0;

  for (size_t i = start; i < end; i++) {
    strd[len++] = stro[i];
  }
  strd[len] = '\0';
}

int main() {
  char str[MAXLEN];
  size_t lenStr;

  char substr[MAXLEN];
  size_t lenSubstr;

  char newSubstr[MAXLEN];
  size_t lenNewSubstr;

  char firstPart[MAXLEN/2];
  char lastPart[MAXLEN/2];

  char *strTemp;
  size_t lenStrTemp;

  fprintf(stdout, "\n\tDigite algo\n> ");
  fgets(str, MAXLEN, stdin);
  str[strlen(str)-1] = 0;
  lenStr = strlen(str);

  fprintf(stdout, "\n\tSubstring\n> ");
  fgets(substr, MAXLEN, stdin);
  substr[strlen(substr)-1] = 0;
  lenSubstr = strlen(substr);

  fprintf(stdout, "\n\tNova Substring\n> ");
  fgets(newSubstr, MAXLEN, stdin);
  newSubstr[strlen(newSubstr)-1] = 0;
  lenNewSubstr = strlen(newSubstr);

  strTemp = strstr(str, substr);
  lenStrTemp = strlen(strTemp);

  slice(str, firstPart, 0, lenStr-lenStrTemp);
  slice(strTemp, lastPart, lenSubstr, lenStrTemp);

  size_t lenNewStr = strlen(firstPart)+lenNewSubstr+strlen(lastPart);
  char newStr[lenNewStr];

  strcpy(newStr, firstPart);
  strcat(newStr, newSubstr);
  strcat(newStr, lastPart);

  printf("\n\n\tString original => “%s“ [%d]\n", str, lenStr);
  printf(
    "\t“%s“ [%d] foi substituida por “%s“ [%d]\n",
    substr, lenSubstr, newSubstr, lenNewSubstr
  );
  printf("\tA nova string é => “%s“ [%d]\n\n\n", newStr, lenNewStr);

  return 0;
}
