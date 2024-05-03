#include "Gol.h"

int main()
{
    const int WIDTH = 20;
    const int HEIGHT = 20;
    bool **map = new bool *[WIDTH];
    bool **new_map = new bool *[HEIGHT];
    Gol::playTheGameOfLife(WIDTH, map, HEIGHT, new_map);

    return 0;
}
