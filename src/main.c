// TODO
/*

1. Returning a local array in generate_cell() (`int cell[x][y]; return cell;`) –
invalid in C.
2. **`int cell[][]` in `check_neighbors()`** – C requires at least the second
dimension (`int cell[HEIGHT][WIDTH]`).
3. **`return 0;` in a void function** – invalid.
4. **Declaring a new grid every loop iteration in `main()`** – loses previous
generation state.
5. **`srand(time(NULL))` inside a function** – should only run once in `main()`.
6. **Reinitializing grid inside `grid_update()` every call** – overwrites
current state.
7. **Using loops like `for (int i = 0; i < grid[HEIGHT]; i++)`** – must use the
size variable, not `grid[HEIGHT]`.

*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum State {
  DEAD = 0,
  ALIVE = 1,
};

const int HEIGHT = 100;
const int WIDTH = 100;

void grid_update(int grid[][]) {

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (grid[i][j] == DEAD) {
        printf(".");
      } else {
        printf("*");
      }
    }
    printf("\n");
  }
}

void generate_cell(int grid[HEIGHT][WIDTH]) {
  srand(time(NULL));

  int x = rand() % WIDTH;
  int y = rand() % HEIGHT;

  int cell[x][y];
  return cell;
}

void check_neighbors(int cell[][]) { return 0; }

int main() {
  grid_update();

  while (true) {
    int cell[HEIGHT][WIDTH];
    generate_cell(cell);
    check_neighbors(cell);
  }
  return 0;
}
