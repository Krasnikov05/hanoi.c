#include "algorithm.h"
#include "display.h"

#define move(a, b)                                                             \
  if (1) {                                                                     \
    push(&stacks[indices[b]], pop(&stacks[indices[a]]));                       \
    display_stacks(3, rings, stacks);                                          \
  }

void _solve(size_t rings, size_t in_use, Stack *stacks, size_t indices[]) {
  if (in_use > 3) {
    size_t indices1[] = {indices[0], indices[2], indices[1]};
    _solve(rings, in_use - 1, stacks, indices1);
    move(0, 2);
    size_t indices2[] = {indices[1], indices[0], indices[2]};
    _solve(rings, in_use - 1, stacks, indices2);
    return;
  }
  move(0, 2);
  move(0, 1);
  move(2, 1);
  move(0, 2);
  move(1, 0);
  move(1, 2);
  move(0, 2);
}

#undef move

void solve(size_t rings, Stack *stacks) {
  display_stacks(3, rings, stacks);
  size_t indices[] = {0, 1, 2};
  _solve(rings, rings, stacks, indices);
}
