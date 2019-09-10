#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>   /* for errno */
#include <unistd.h>  /* for EINTR */
#include <termios.h>
#include <sys/time.h>

#define MAXLEN 17

void getInputMaskingOutput(char **str, size_t len, char mask, FILE *fp) {
  /* index, number of chars in read */
  char ch;
  size_t index = 0;

  /* orig keyboard settings */
  struct termios old_kbd_mode;
  struct termios new_kbd_mode;

  /* save orig settings   */
  tcgetattr(0, &old_kbd_mode);

  /* copy old to new */
  memcpy(&new_kbd_mode, &old_kbd_mode, sizeof(struct termios));

  /* new kbd flags */
  new_kbd_mode.c_lflag &= ~(ICANON | ECHO);
  new_kbd_mode.c_cc[VTIME] = 0;
  new_kbd_mode.c_cc[VMIN] = 1;

  tcsetattr(0, TCSANOW, &new_kbd_mode);

  /* read chars from fp, mask if valid char specified */
  while (
    ((ch = fgetc(fp)) != '\n' && ch != EOF && index < len - 1) ||
    (index == len - 1 && ch == 127)
  ) {
    if (ch != 127) {
      /* valid ascii char */
      if (31 < mask && mask < 127) fputc(mask, stdout);

      (*str)[index++] = ch;
    } else {
      /* handle backspace (del) */
      if (index > 0) {
        if (31 < mask && mask < 127) {
          fputc (0x8, stdout);
          fputc (' ', stdout);
          fputc (0x8, stdout);
        }

        (*str)[--index] = 0;
      }
    }
  }

  (*str)[index] = 0; /* null-terminate */

  /* reset original keyboard */
  tcsetattr(0, TCSANOW, &old_kbd_mode);
}

int main() {
  char password[MAXLEN] = {0};
  char correctPassword[] = "adm";

  char *ptrPassword = password;
  FILE *ptrArc = stdin;

  printf("\n\tEntre com a senha\n> ");
  getInputMaskingOutput(&ptrPassword, MAXLEN, '*', ptrArc);

  printf("\n\n\t");

  if (!strcmp(password, correctPassword)) printf("Senha CORRETA!");
  else printf("Senha INCORRETA!!!");

  printf("\n\n");

  return 0;
}
