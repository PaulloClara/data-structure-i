void loginGenerator(char *name, char *username, size_t len) {  /* q09 */
  for (size_t i = 0; i < len; i++) {
    username[i] = name[i];
  }
  username[len] = '\0';
}

void substr(char *stro, char *strd, size_t start, size_t end) { /* q10 */
  size_t len = 0;

  for (size_t i = start; i < end; i++) {
    strd[len++] = stro[i];
  }
  strd[len] = '\0';
}
