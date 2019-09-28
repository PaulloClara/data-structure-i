/*
  Made and tested on Linux!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct t_tag{
  char value[20];
  char type;              // o == opening || c == closing
  struct t_tag *next;
} t_tag;

typedef struct {
  size_t size;
  t_tag *top;
} t_stack;

void clear_buffer() {
  char ch;
  while((ch = fgetc(stdin)) != EOF && ch != '\n' ) continue;
}

void clear_screen() {
  system("clear");
}

void init(t_stack *stack) {
  stack->size = 0;
  stack->top = NULL;
}

size_t void_stack(t_stack *stack) {
  return stack->size == 0 ? TRUE: FALSE;
}

void push(t_stack *stack, char *str, char type) {
  t_tag *tag;
  tag = (t_tag*) malloc(sizeof(t_tag));

  if (tag != NULL) {
    strcpy(tag->value, str);
    tag->type = type;
    tag->next = stack->top;
    stack->top = tag;
    stack->size++;
  } else printf("\n\nCould not allocate memory!\n");
}

void pop(t_stack *stack, char *str) {
  t_tag *tag;
  
  tag = stack->top;
  stack->top = tag->next;
  stack->size--;
  strcpy(str, tag->value);

  free(tag);
  tag = NULL;
}

char check_type(char *str) {
  if (str[0] == '<' && str[1] == '/') return 'c';
  return 'o';
}

size_t check_closing_tag(t_stack *stack, char *str, char type) {
  if (type != stack->top->type && strcmp(stack->top->value, str) == 0)
    return TRUE;
  return FALSE;
}

size_t check_closing_tag_dup(t_stack *stack, char *str, char type) {
  if (type == 'c' && strcmp(stack->top->value, str) != 0) return FALSE;
  return TRUE;
}

void clear_tag(char *str, char type) {
  size_t start = 1;
  char newstr[20];

  if (type == 'c') start++;

  for (size_t i = start; i < strlen(str)-1; i++) {
    newstr[i-start] = str[i];
  }

  strcpy(str, newstr);
}

void show(t_stack *stack) {
  t_tag *tag;

  if (void_stack(stack) == FALSE) {
    tag = stack->top;

    printf("\n\n\n");
    do {
      printf("\tElement: ");

      if (tag->type == 'o') printf("<");
      else printf("</");

      printf("%s>\n", tag->value);

      tag = tag->next;
    } while (tag != NULL);
  } else printf("\n\n\tStack void!\n");
}

int main() {
  char ch;
  char type;
  char str[20];
  t_stack stack;

  init(&stack);

  do {
    clear_screen();

    printf("\n\tTag: ");
    fgets(str, 20, stdin);
    str[strlen(str)-1] = '\0';

    type = check_type(str);

    clear_tag(str, type);

    if (void_stack(&stack) && type == 'o')
      push(&stack, str, type);
    else if (void_stack(&stack) || !check_closing_tag_dup(&stack, str, type))
      printf("\n\tUnexpected tag\n\n");
    else if (check_closing_tag(&stack, str, type))
      pop(&stack, str);
    else push(&stack, str, type);

    show(&stack);

    printf("\n\n\tContinue? Y/n\n> "); ch = fgetc(stdin);
    if (ch != '\n') clear_buffer();
  } while (ch != 'n' && ch != 'N');

  return 0;
}