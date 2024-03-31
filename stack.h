#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdlib.h>

#define LINKED_LIST

#ifdef LINKED_LIST

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef Node *Stack;

#else /* LINKED_LIST */

#define CAPACITY 100

typedef struct {
  size_t len;
  int arr[CAPACITY];
} Stack;

#endif /* LINKED_LIST */

void init_stack(Stack *stack);
void push(Stack *stack, int data);
int pop(Stack *stack);
void repr_stack(Stack *stack);
bool is_empty(Stack *stack);
size_t length(Stack *stack);

#endif /* STACK_H */
