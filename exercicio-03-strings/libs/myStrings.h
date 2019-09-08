size_t getSlice(char *stringO, char *stringD, int start, int end) {
  size_t len = 0;

  for (size_t i = start; i < end; i++) {
    stringD[len++] = stringO[i];
  }
  stringD[len] = 0;

  return len;
}
