// TOOD: create a visualisation

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

enum State {
  DEAD = 0,
  ALIVE = 1,
};

#define SPEED 1 // amount of alive cells each frame
#define WIDTH 100
#define HEIGHT 50

void screen_print(int grid[HEIGHT][WIDTH]) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf(grid[i][j] == DEAD ? "." : "*");
    }
    printf("\n");
  }
}

void generate_cells(int grid[HEIGHT][WIDTH], int speed) {

  for (int i = 0; i < speed; i++) {
    int y = rand() % HEIGHT;
    int x = rand() % WIDTH;

    grid[y][x] = ALIVE;
  }
}

void check_neighbors() {}

int main() {
  srand(time(NULL)); // seeding the rnd

  int grid[HEIGHT][WIDTH] = {0}; // initialize the grid

  while (true) {
    system("clear");
    generate_cells(grid, SPEED);
    screen_print(grid);
    sleep(1); // one second delay between frames
  }

  return 0;
}
