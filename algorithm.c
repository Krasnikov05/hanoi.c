#include "algorithm.h"
#include "display.h"

#ifdef RECURSIVE

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

#else /* RECURSIVE */

void move(Stack *stacks, size_t n, size_t m) {
  if (is_empty(&stacks[n])) {
    push(&stacks[n], pop(&stacks[m]));
    return;
  }
  if (is_empty(&stacks[m])) {
    push(&stacks[m], pop(&stacks[n]));
    return;
  }
  int nval = pop(&stacks[n]);
  int mval = pop(&stacks[m]);
  if (nval < mval) {
    push(&stacks[m], mval);
    push(&stacks[m], nval);
  } else {
    push(&stacks[n], nval);
    push(&stacks[n], mval);
  }
}

void solve(size_t rings, Stack *stacks) {
  display_stacks(3, rings, stacks);
  int moves = 1;
  int i;
  for (i = 0; i < (int)rings; i++) {
    moves *= 2;
  }
  moves -= 1;
  int n, m;
  int b = 1;
  int c = 2;
  if (rings % 2 == 0) {
    b = 2;
    c = 1;
  }
  for (i = 1; i <= moves; i++) {
    if (i % 3 == 0) {
      n = c;
      m = b;
    } else if (i % 3 == 1) {
      n = 0;
      m = c;
    } else {
      n = 0;
      m = b;
    }
    move(stacks, n, m);
    display_stacks(3, rings, stacks);
  }
}

#endif /* RECURSIVE */
