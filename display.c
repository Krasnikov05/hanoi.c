#include "display.h"
#include "stack.h"
#include <stdio.h>

void display_stacks(size_t rods, size_t rings, Stack *stacks) {
#ifdef ONLY_REPR
  size_t i;
  printf("-------------\n");
  for (i = 0; i < rods; i++) {
    repr_stack(&stacks[i]);
  }
  return;
#else  /* ONLY_RERP */
  int top[rods];
  Stack saved[rods];
  size_t i, j, k;
  for (i = 0; i < rods; i++) {
    printf("\e[K");
    repr_stack(&stacks[i]);
    top[i] = rings + 1 - length(&stacks[i]);
    saved[i] = NULL;
  }
  for (i = 0; i < rings + 1; i++) {
    for (j = 0; j < rods; j++) {
      if (top[j]-- > 0) {
        for (k = 0; k < rings; k++) {
          printf(" ");
        }
        printf("|");
        for (k = 0; k < rings; k++) {
          printf(" ");
        }
      } else {
        int data = pop(&stacks[j]);
        push(&saved[j], data);
        for (k = 0; k < rings + 1; k++) {
          printf(k < rings - data ? " " : "#");
        }
        for (k = 0; k < rings; k++) {
          printf((int)k < data ? "#" : " ");
        }
      }
      printf("    ");
    }
    printf("\n");
  }
  for (i = 0; i < rods; i++) {
    while (!is_empty(&saved[i]))
      push(&stacks[i], pop(&saved[i]));
  }
  printf("\e[%ldA", rings + rods + 2);
#endif /* ONLY_REPR */
  getchar();
}
