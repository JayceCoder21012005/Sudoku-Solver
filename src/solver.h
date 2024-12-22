#pragma once

class Solver {
public:
    Solver(int board[9][9]);
    bool solveSudoku();
    bool isValidPlacement(int row, int col, int num);
    void printBoard();
    void getSolvedBoard(int solvedBoard[9][9]);
    // inline static bool isSolved = false;
private:
    int board[9][9];
    bool findEmptyLocation(int &row, int &col);
};