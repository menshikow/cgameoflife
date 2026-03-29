#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 100
#define HEIGHT 50
#define INITIAL_DENSITY 500

enum State {
  DEAD = 0,
  ALIVE = 1,
};

void screen_print(int grid[HEIGHT][WIDTH]) {
  printf("\033[H"); // move cursor to top-left

  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      putchar(grid[y][x] ? '*' : '.');
    }
    putchar('\n');
  }
}

void generate_cells(int grid[HEIGHT][WIDTH], int count) {
  for (int i = 0; i < count; i++) {
    int y = rand() % HEIGHT;
    int x = rand() % WIDTH;
    grid[y][x] = ALIVE;
  }
}

int check_neighbors(int grid[HEIGHT][WIDTH], int y, int x) {
  int count = 0;

  for (int dy = -1; dy <= 1; dy++) {
    for (int dx = -1; dx <= 1; dx++) {
      if (dx == 0 && dy == 0)
        continue;

      int ny = (y + dy + HEIGHT) % HEIGHT;
      int nx = (x + dx + WIDTH) % WIDTH;

      count += grid[ny][nx];
    }
  }

  return count;
}

int next_state(int grid[HEIGHT][WIDTH], int y, int x) {
  int n = check_neighbors(grid, y, x);

  if (grid[y][x] == ALIVE)
    return (n == 2 || n == 3) ? ALIVE : DEAD;
  else
    return (n == 3) ? ALIVE : DEAD;
}

void iterate_grid(int current[HEIGHT][WIDTH], int next[HEIGHT][WIDTH]) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      next[y][x] = next_state(current, y, x);
    }
  }
}

int main(void) {
  srand(time(NULL));

  int grid1[HEIGHT][WIDTH] = {0};
  int grid2[HEIGHT][WIDTH] = {0};

  int (*current)[WIDTH] = grid1;
  int (*next)[WIDTH] = grid2;

  generate_cells(current, INITIAL_DENSITY);

  printf("\033[2J"); // clear screen once

  while (1) {
    screen_print(current);
    iterate_grid(current, next);

    // swap grids
    int (*tmp)[WIDTH] = current;
    current = next;
    next = tmp;

    usleep(100000);
  }

  return 0;
}