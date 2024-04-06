CC := gcc
files := algorithm.c display.c main.c stack.c
all: hanoi
hanoi: $(files)
	$(CC) -Wall -Wextra -std=c90 -O3 $(files) -o $@
