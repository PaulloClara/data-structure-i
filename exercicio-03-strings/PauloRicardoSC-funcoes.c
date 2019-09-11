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

float convertMsToKmh(float ms) {  /* 14 */
  return ms * 3.6;
}

size_t convertHrMntToMnt(size_t hr, size_t mnt) { /* 15 */
  return mnt + hr * 60;
}

float convertUSDToBRL(float usdval, float usd) { /* 16 */
  return usd * usdval;
}

float convertKmhToMs(float kmh) {  /* 17 */
  return kmh / 3.6;
}

float calcAT(float b, float h) {  /* 18 */
  return b * h / 2;
}

float calcAQ(float l) {  /* 19 */
  return l * l;
}

float calcAR(float b, float h) { /* 20 */
  return b * h;
}

float calcCC(float r) {  /* 21 */
  return 2 * 3.1415 * r;
}

float calcVE(float r) {  /* 22 */
  return 4 * 3.1415 * (r*r*r) / 3;
}

float convertCF(float c) {  /* 23 */
  return (c * 9 + 160) / 5;
}

float convertFC(float f) {  /* 24 */
  return (f * 5 - 160) / 9;
}

size_t calcF(size_t n) {  /* 25 */
  size_t result = 1;

  for (size_t i = 2; i < n+1; i++) {
    result *= i;
  }

  return result;
}

size_t checkNumberPrime(size_t n) {  /* 26 */
  if (n == 2 || n == 3 || n == 5 || n == 7) return 1;
  if (!(n%2) || !(n%3) || !(n%5) || !(n%7)) return 0;

  return 1;
}

size_t checkDate(char *date) {  /* 27 */
  size_t i = 0;

  if (date[i] < '0' || date[i] > '3') return 0;
  i++;
  if (date[i] < '1' || date[i] > '9') return 0;
  i++;
  if (date[i] == '/') i++;
  if (date[i] < '0' || date[i] > '1') return 0;
  i++;
  if (date[i] < '1' || (date[i-1] == '0' && date[i] > '9') || (date[i-1] == '1' && date[i] > '2')) return 0;
  i++;
  if (date[i] == '/') i++;
  for (size_t j = 0; j < 4; j++) {
    if (date[i+j] < '0' || date[i] > '9') return 0;
  }

  if (date[i+4] != '\n' && date[i+4] != '\0') return 0;

  return 1;
}

size_t mmc(int n1, int n2) {  /* 28 */
  size_t mmc, aux;

  for (size_t i = 2; i <= n2; i++) {
    aux = n1 * i;
    if ((aux % n2) == 0) {
      mmc = aux;
      i = n2 + 1;
    }
  }

  return mmc;
}

size_t mdc(size_t n1, size_t n2) {  /* 29 */
  size_t remainder;

  do {
    remainder = n1 % n2;

    n1 = n2;
    n2 = remainder;

  } while (remainder != 0);

  return n1;
}
