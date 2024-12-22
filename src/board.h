#include <raylib.h>

class Board {
public:
    Board();
    void initializeBoard();
    void displayBoard();
    void drawGrid(float opacity = 1.0f);
    bool validateBoard();
    int board[9][9];

private:
    bool isValid(int row, int col, int num);
};