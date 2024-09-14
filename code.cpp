#include <iostream>
#include <vector>
#define UNASSIGNED 0
#define N 9
using namespace std;

class Game {
public:
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    void generateSudoku(int difficultyLevel) {
        // Based on the difficulty level, you can remove more elements from the grid
        // For simplicity, we won't implement grid modification here. 
        // You can add logic to remove difficultyLevel cells from the grid
        // to create a playable Sudoku puzzle.
    }

    void printSudoku() {
        printGrid(grid);
    }

    void play() {
        if (solveSudoku(grid)) {
            cout << "\nSolved Sudoku Board:\n";
            printGrid(grid);
        } else {
            cout << "No solution exists";
        }
    }

private:
    bool isSafe(int grid[N][N], int row, int col, int num) {
        for (int x = 0; x < N; x++)
            if (grid[row][x] == num)
                return false;

        for (int x = 0; x < N; x++)
            if (grid[x][col] == num)
                return false;

        int startRow = row - row % 3, startCol = col - col % 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (grid[i + startRow][j + startCol] == num)
                    return false;

        return true;
    }

    bool solveSudoku(int grid[N][N]) {
        int row, col;
        bool isEmpty = true;
        for (row = 0; row < N; row++) {
            for (col = 0; col < N; col++) {
                if (grid[row][col] == UNASSIGNED) {
                    isEmpty = false;
                    break;
                }
            }
            if (!isEmpty) {
                break;
            }
        }

        if (isEmpty) {
            return true;
        }

        for (int num = 1; num <= N; num++) {
            if (isSafe(grid, row, col, num)) {
                grid[row][col] = num;

                if (solveSudoku(grid))
                    return true;

                grid[row][col] = UNASSIGNED;
            }
        }
        return false;
    }

    void printGrid(int grid[N][N]) {
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++)
                cout << grid[row][col] << " ";
            cout << endl;
        }
    }
};

int main() {
    int difficultyLevel;
    do {
        cout << "\nEnter difficulty level :\n1. 40 for easy.\n2. 30 for medium\n3. 20 for hard\n ";
        cin >> difficultyLevel;

        if (difficultyLevel == 20 || difficultyLevel == 30 || difficultyLevel == 40) {
            break;
        } else
            cout << "Invalid Input! Enter again: \n";
    } while (true);

    Game sudokuGame;
    sudokuGame.generateSudoku(difficultyLevel);

    cout << "\nInitial Sudoku Board:\n";
    sudokuGame.printSudoku();

    sudokuGame.play();

    return 0;
}