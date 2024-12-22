#include "solver.h"
#include <iostream>

Solver::Solver(int board[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            this->board[i][j] = board[i][j];
        }
    }
}

bool Solver::isValidPlacement(int row, int col, int num) {
    // Check if 'num' is not in the current row
    for (int x = 0; x < 9; x++) {
        if (board[row][x] == num) {
            return false;
        }
    }

    // Check if 'num' is not in the current column
    for (int x = 0; x < 9; x++) {
        if (board[x][col] == num) {
            return false;
        }
    }

    // Check if 'num' is not in the current 3x3 box
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool Solver::solveSudoku() {
    int row, col;

    // Find an empty space in the board
    if (!findEmptyLocation(row, col)) {
        return true; // Puzzle solved
    }

    // Try numbers 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (isValidPlacement(row, col, num)) {
            board[row][col] = num;

            // Recursively attempt to solve the rest of the board
            if (solveSudoku()) {
                return true;
            }

            // If it doesn't lead to a solution, reset and try next number
            board[row][col] = 0;
        }
    }
    return false;
}

bool Solver::findEmptyLocation(int &row, int &col) {
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

void Solver::printBoard() {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            std::cout << board[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void Solver::getSolvedBoard(int solvedBoard[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            solvedBoard[i][j] = board[i][j];
        }
    }
}