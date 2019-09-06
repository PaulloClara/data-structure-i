/*
  Essa lib foi feita de partes de codigos encontrados na web e extremamente
  adaptados para o mundo linux.
*/

#include <errno.h>   /* for errno */
#include <unistd.h>  /* for EINTR */
#include <termios.h>
#include <sys/time.h>

int getInputMaskingOutput(char **string, int len, int mask, FILE *fp) {
  /* validate input */
  if (!string || !len || !fp) return -1;

  /* reallocate if no address */
  if (*string == NULL) {
    void *tmp = realloc(*string, len * sizeof **string);
    if (!tmp) return -1;

    /* initialize memory to 0 */
    memset (tmp, 0, len);
    *string = tmp;
  }

  /* index, number of chars in read */
  int index = 0;
  int c = 0;

  /* orig keyboard settings */
  struct termios old_kbd_mode;
  struct termios new_kbd_mode;

  /* save orig settings   */
  if (tcgetattr(0, &old_kbd_mode)) {
    fprintf(stderr, "%s() error: tcgetattr failed.\n", __func__);
    return -1;
  }

  /* copy old to new */
  memcpy(&new_kbd_mode, &old_kbd_mode, sizeof(struct termios));

  /* new kbd flags */
  new_kbd_mode.c_lflag &= ~(ICANON | ECHO);
  new_kbd_mode.c_cc[VTIME] = 0;
  new_kbd_mode.c_cc[VMIN] = 1;

  if (tcsetattr(0, TCSANOW, &new_kbd_mode)) {
    fprintf(stderr, "%s() error: tcsetattr failed.\n", __func__);
    return -1;
  }

  /* read chars from fp, mask if valid char specified */
  while (
    ((c = fgetc(fp)) != '\n' && c != EOF && index < len - 1) ||
    (index == len - 1 && c == 127)
  ) {
    if (c != 127) {
      /* valid ascii char */
      if (31 < mask && mask < 127) fputc(mask, stdout);

      (*string)[index++] = c;
    } else {
      /* handle backspace (del) */
      if (index > 0) {
        if (31 < mask && mask < 127) {
          fputc (0x8, stdout);
          fputc (' ', stdout);
          fputc (0x8, stdout);
        }

        (*string)[--index] = 0;
      }
    }
  }

  (*string)[index] = 0; /* null-terminate */

  /* reset original keyboard */
  if (tcsetattr (0, TCSANOW, &old_kbd_mode)) {
    fprintf(stderr, "%s() error: tcsetattr failed.\n", __func__);
    return -1;
  }

  if (index == len - 1 && c != '\n') /* warn if string truncated */
    fprintf(stderr, " (%s() warning: truncated at %zu chars.)\n", __func__, len - 1);

  return index; /* number of chars in string */
}
