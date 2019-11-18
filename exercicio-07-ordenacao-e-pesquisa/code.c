#include <stdio.h>
#include <stdlib.h>

#define MAXUSERINPUT 100
#define MAXCHARNUMBERINPUT 12

int main() {
  int array[MAXUSERINPUT/2];
  size_t array_size = 0;

  // user input code
  char user_input[MAXUSERINPUT];

  char temp[MAXCHARNUMBERINPUT];
  size_t temp_size = 0;

  printf("\n\tArray Ex: \"0 5 2 9 2 5 1 0\"\n> ");
  fgets(user_input, MAXUSERINPUT, stdin);

  for (size_t i = 0; i < MAXUSERINPUT; i++) {
    if (user_input[i] == ' ' || user_input[i] == '\n') {
      temp[temp_size] = '\0';
      temp_size = 0;

      array[array_size++] = atoi(temp);
    } else temp[temp_size++] = user_input[i];

    if (user_input[i] == '\n' || user_input[i] == '\0') break;
  }

  // counting sort code
  int index_array_size = 0;
  int new_array[array_size];

  for (size_t i = 0; i < array_size; i++)
    if (index_array_size < array[i]) index_array_size = array[i];

  int index_array[++index_array_size];

  for (size_t i = 0; i < index_array_size; i++)
    index_array[i] = 0;

  for (size_t i = 0; i < array_size; i++)
    index_array[array[i]]++;

  for (size_t i = 1; i < index_array_size; i++)
    index_array[i] += index_array[i-1];

  for (size_t i = 0; i < array_size; i++)
    new_array[--index_array[array[i]]] = array[i];

  // output code
  printf("\n\n\tNew Array: [");
  for (size_t i = 0; i < array_size; i++) printf("%i, ", new_array[i]);
  printf("\b\b]\n\n\n");

  return 0;
}
