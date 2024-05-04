#ifndef GOL_H
#define GOL_H
namespace Gol
{
    // Function prototype: playTheGameOfLife
    void playTheGameOfLife(const int WIDTH, bool **map, const int HEIGHT, bool **new_map);

    // Function prototype: initaliseBoard
    void initaliseBoard(const int WIDTH, const int HEIGHT, bool **map, bool **new_map);

    // Function prototype: populateNextFrame
    void populateNextFrame(const int WIDTH, const int HEIGHT, bool **map, bool **new_map);

    // Function prototype: copyToCurrentFrame
    void copyToCurrentFrame(const int WIDTH, const int HEIGHT, bool **map, bool **new_map);

    // Function prototype: checkAroundCurrentCoordReturnCount
    int checkAroundCurrentCoordReturnCount(int outer, int inner, const int HEIGHT, const int WIDTH, bool **map);

    // Function prototype: wrapChecks
    void wrapChecks(int &y, const int HEIGHT, int &x, const int WIDTH);

    // Function prototype: printBoard
    void printBoard(int height, int width, bool **map);
}
#endif