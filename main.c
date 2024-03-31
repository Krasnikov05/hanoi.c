#include "algorithm.h"
#include "stack.h"
#include <stdio.h>

int main(int argc, char **argv) {
  Stack stacks[3];
  size_t s;
  for (s = 0; s < 3; s++)
    init_stack(&stacks[s]);
  int rings = 5;
  if (argc == 2) {
    rings = atoi(argv[1]);
  }
  int i = rings;
  while (i) {
    push(&stacks[0], i);
    i--;
  }
  solve(rings, stacks);
  for (i = 0; i < rings + 4; i++) {
    printf("\n");
  }
  return 0;
}
