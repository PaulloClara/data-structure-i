#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct t_element{
  size_t value;
  struct t_element *next;
} t_element;

typedef struct {
  size_t size;
  t_element *top;
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

size_t size(t_stack *stack) {
  return stack->size;
}

void push(t_stack *stack, size_t value) {
  t_element *element;
  element = (t_element*) malloc(sizeof(t_element));

  if (element != NULL) {
    element->value = value;
    element->next = stack->top;
    stack->top = element;
    stack->size++;
  } else printf("\n\nCould not allocate memory!\n");
}

size_t pop(t_stack *stack) {
  size_t value;
  t_element *element;
  
  element = stack->top;
  stack->top = element->next;
  stack->size--;
  value = element->value;

  free(element);
  element = NULL;

  return value;
}

void calculate(t_stack *stack, char op) {
  size_t result;
  size_t value2 = pop(stack);
  size_t value1 = pop(stack);

  if (op == '+') result = value1 + value2;
  else if (op == '-') result = value1 - value2;
  else if (op == '*') result = value1 * value2;
  else result = value1 / value2;
  
  push(stack, result);
}

void show(t_stack *stack) {
  t_element *element;

  if (void_stack(stack) == FALSE) {
    element = stack->top;

    printf("\n\n\n");
    do {
      printf("\tElement: %d\n", element->value);
      element = element->next;
    } while (element != NULL);

  } else printf("\n\n\tStack void!\n");
}

int main() {
  char op;
  size_t calc;
  size_t value;
  t_stack stack;

  init(&stack);

  do {
    clear_screen();

    if (size(&stack) > 1) {
      printf("\n\tInsert operator? Y/n\n> ");
      calc = (fgetc(stdin)) != 'n' ? TRUE : FALSE;
    }

    if (calc) {
      printf("\n\tOperator\n> ");
      op = fgetc(stdin);
      clear_buffer();
      
      calculate(&stack, op);
      
      calc = FALSE;
    } else {
      printf("\n\tValue\n> ");
      scanf("%d", &value);
      clear_buffer();
      
      push(&stack, value);
    }

    show(&stack);

    printf("\n\n\tContinuar? Y/n\n> ");
  } while ((fgetc(stdin)) != 'n');

  return 0;
}