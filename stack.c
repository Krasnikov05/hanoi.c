#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef LINKED_LIST

void init_stack(Stack *stack) { *stack = NULL; }

void push(Stack *stack, int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL) {
    fprintf(stderr, "MEMORY ALLOCATION FALIED!\n");
    exit(1);
  }
  node->data = data;
  node->next = NULL;
  if (*stack == NULL) {
    *stack = node;
    return;
  }
  Node *last = *stack;
  while (last->next) {
    last = last->next;
  }
  last->next = node;
}

int pop(Stack *stack) {
  if ((**stack).next == NULL) {
    int data = (**stack).data;
    free(*stack);
    *stack = NULL;
    return data;
  }
  Node *penult = *stack;
  while (penult->next->next) {
    penult = penult->next;
  }
  int data = penult->next->data;
  free(penult->next);
  penult->next = NULL;
  return data;
}

void repr_stack(Stack *stack) {
  Node *node = *stack;
  printf("[");
  while (node) {
    printf("%d", node->data);
    if (node->next)
      printf(", ");
    node = node->next;
  }
  printf("]\n");
}

bool is_empty(Stack *stack) { return *stack == NULL; }

size_t length(Stack *stack) {
  size_t len = 0;
  Node *node = *stack;
  while (node) {
    len++;
    node = node->next;
  }
  return len;
}

#else

void init_stack(Stack *stack) { stack->len = 0; }

void push(Stack *stack, int data) { stack->arr[stack->len++] = data; }

int pop(Stack *stack) { return stack->arr[--stack->len]; }

void repr_stack(Stack *stack) {
  size_t i;
  printf("[");
  for (i = 0; i + 1 < stack->len; i++)
    printf("%d, ", stack->arr[i]);
  printf("%d", stack->arr[i]);
  printf("]\n");
}

bool is_empty(Stack *stack) { return stack->len == 0; }

size_t length(Stack *stack) { return stack->len; }

#endif
