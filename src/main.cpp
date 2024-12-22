#include <raylib.h>
#include "board.h"
#include "solver.h"
#include <iostream>

int main() {
    InitWindow(600, 800, "Sudoku Solver");
    SetTargetFPS(60);

    Board sudokuBoard;
    sudokuBoard.initializeBoard();

    Solver sudokuSolver(sudokuBoard.board);

    bool solved = false;
    bool noSolution = false;
    float opacity = 0.0f;

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_ESCAPE)) {
            break; // Exit the loop when ESC is pressed
        }

        BeginDrawing();
        ClearBackground(DARKBLUE);

        sudokuBoard.drawGrid(opacity);

        if (IsKeyPressed(KEY_SPACE) && !solved && !noSolution) {
            if (sudokuSolver.solveSudoku()) {
                sudokuSolver.getSolvedBoard(sudokuBoard.board);
                solved = true;
            } else {
                noSolution = true;
            }
        }

        if (noSolution) {
            DrawText("No solution exists", 150, 700, 20, RED);
            DrawText("Press 'Y' to continue or 'N' to exit", 100, 730, 20, RED);

            if (IsKeyPressed(KEY_Y)) {
                sudokuBoard.initializeBoard();
                sudokuSolver = Solver(sudokuBoard.board);
                solved = false;
                noSolution = false;
                opacity = 0.0f;
            } else if (IsKeyPressed(KEY_N)) {
                break; // Exit the loop when 'N' is pressed
            }
        }

        if (IsKeyPressed(KEY_ENTER) && !noSolution) {
            sudokuBoard.initializeBoard();
            sudokuSolver = Solver(sudokuBoard.board);
            solved = false;
            opacity = 0.0f; // Reset opacity
        }

        if (solved && opacity < 1.0f) {
            opacity += 0.005f; // Increase opacity gradually
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}