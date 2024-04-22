#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

void fractal(int x, int y, int depth, int color) {
    if (depth == 0) {
        printf("  pixel %d,%d color %d\n", x, y, color);
        return;
    }

    int new_depth = depth - 1;
    int new_x = x + (rand() % 3) - 1;
    int new_y = y + (rand() % 3) - 1;

    fractal(new_x, new_y, new_depth, color);
    fractal(x, y + 2, new_depth, color);
    fractal(x + 2, y, new_depth, color);
    fractal(x + 2, y + 2, new_depth, color);
}

int main() {
    srand(time(0));

    printf("P3\n%d %d\n255\n", WIDTH, HEIGHT);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fractal(x, y, 3, rand() % 256);
        }
    }

    return 0;
}