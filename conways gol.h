#pragma once
void printBoard(int w, int h, bool **map);

void populateNextFrame(const int WIDTH, const int HEIGHT, bool **map, bool **new_map);

void initaliseBoard(const int WIDTH, const int HEIGHT, bool **map);
