#include <stdio.h>
#include <stdlib.h>

// functions and pointers off

int main () {
  int v1[5] = {0, 1, 2, 3, 4};
  int len1 = sizeof(v1)/sizeof(v1[0]);

  int v2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int len2 = sizeof(v2)/sizeof(v2[0]);

  int len3 = sizeof(v1)/sizeof(v1[0]) + sizeof(v2)/sizeof(v2[0]);
  int v3[len3];

  for (int i = 0; i < len1; i++) {
    v3[i] = v1[i];
  }

  for (int i = 0; i < len2; i++) {
    v3[i+len1] = v2[i];
  }

  for (int i = 0; i < len3; i++) {
    printf("%d\n", v3[i]);
  }

  // system ("pause");
  return 0;
}
