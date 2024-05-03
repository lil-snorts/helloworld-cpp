#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h> /* srand, rand */
#include <chrono>
#include <thread>
#include "conways gol.h"

int main()
{
    const int WIDTH = 10;
    const int HEIGHT = 10;
    bool **map = new bool *[WIDTH];
    bool **new_map = new bool *[HEIGHT];
    for (int i = 0; i < WIDTH; ++i)
    {
        map[i] = new bool[HEIGHT];
        new_map[i] = new bool[HEIGHT];
    }

    // init board
    initaliseBoard(WIDTH, HEIGHT, &map[0]);
    while (1)
    {

        // print board
        printBoard(HEIGHT, WIDTH, &map[0]);

        // run game
        populateNextFrame(WIDTH, HEIGHT, &map[0], &new_map[0]);
        std::cout << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}

void initaliseBoard(const int WIDTH, const int HEIGHT, bool **map)
{
    for (int outer = 0; outer < WIDTH; outer++)
    {
        for (int inner = 0; inner < HEIGHT; inner++)
        {
            int ran = rand() % 100 + 1;
            if (ran > 84)
            {
                map[outer][inner] = true;
                continue;
            }
        }
    }
}
void populateNextFrame(const int WIDTH, const int HEIGHT, bool **map, bool **new_map)
{
    for (int outer = 0; outer < WIDTH; outer++)
    {
        for (int inner = 0; inner < HEIGHT; inner++)
        {
            int count = 0;
            // check around
            for (int vert = -1; vert < 2; vert++)
            {
                for (int horz = -1; horz < 2; horz++)
                {
                    if (vert == 0 && horz == 0)
                        continue;

                    int y = outer + vert;
                    int x = inner + horz;

                    if (y < 0)
                        y = HEIGHT - 1;
                    else if (y >= HEIGHT)
                        y = 0;

                    if (x < 0)
                        x = WIDTH - 1;
                    if (x >= WIDTH)
                        x = 0;

                    if (map[y][x])
                        count++;
                }
            }
            if (count < 2)
                new_map[outer][inner] = false;
            else if (count == 2)
                new_map[outer][inner] = map[outer][inner];
            else if (count == 3)
                new_map[outer][inner] = true;
            if (count > 4)
                new_map[outer][inner] = false;
        }
    }

    for (int outer = 0; outer < WIDTH; outer++)
    {
        for (int inner = 0; inner < HEIGHT; inner++)
        {
            map[inner][outer] = new_map[inner][outer];
        }
    }
}
void printBoard(int height, int width, bool **map)
{
    for (int outer = 0; outer < height; outer++)
    {
        for (int inner = 0; inner < width; inner++)
        {
            if (map[outer][inner])
                std::cout << "X ";
            else
                std::cout << "_ ";
        }
        std::cout << "\n";
    }
}