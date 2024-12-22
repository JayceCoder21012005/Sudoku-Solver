#include "board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Board::Board() {
    std::srand(std::time(nullptr)); // Seed for random number generation
    initializeBoard();
}

void Board::initializeBoard() {
    // Clear the board
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            board[row][col] = 0;
        }
    }

    // Randomly fill some cells with numbers
    for (int i = 0; i < 20; ++i) { // Fill 20 cells randomly
        int row = std::rand() % 9;
        int col = std::rand() % 9;
        int num = (std::rand() % 9) + 1;
        if (isValid(row, col, num)) {
            board[row][col] = num;
        }
    }
}

void Board::displayBoard() {
    // Display the board in the console (for debugging purposes)
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            std::cout << board[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void Board::drawGrid(float opacity) {
    int cellSize = 60;
    int gridSize = cellSize * 9;
    int offsetX = (GetScreenWidth() - gridSize) / 2;
    int offsetY = (GetScreenHeight() - gridSize) / 2;

    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            int x = offsetX + col * cellSize;
            int y = offsetY + row * cellSize;
            DrawRectangleLines(x, y, cellSize, cellSize, YELLOW);

            if (board[row][col] != 0) {
                DrawText(TextFormat("%d", board[row][col]), x + 20, y + 15, 20, WHITE);
            } else if (opacity > 0) {
                DrawText(TextFormat("%d", board[row][col]), x + 20, y + 15, 20, WHITE);
            }
        }
    }
}

bool Board::validateBoard() {
    // Validate the current state of the board
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (board[row][col] != 0 && !isValid(row, col, board[row][col])) {
                return false;
            }
        }
    }
    return true;
}

bool Board::isValid(int row, int col, int num) {
    // Check if num can be placed at board[row][col]
    for (int x = 0; x < 9; ++x) {
        if (board[row][x] == num || board[x][col] == num || 
            board[row - row % 3 + x / 3][col - col % 3 + x % 3] == num) {
            return false;
        }
    }
    return true;
}