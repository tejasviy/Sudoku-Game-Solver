# Sudoku Game Solver

This C++ program solves a Sudoku game using a backtracking algorithm. It takes a partially filled Sudoku grid as input and fills in the remaining empty cells to solve the Sudoku puzzle.

The program uses a recursive approach to find the solution. It starts by finding an unassigned location (cell with a value of 0) in the grid. Then, it tries different numbers from 1 to 9 to fill the cell, checking if the number is safe to place according to Sudoku rules. If a number is found to be safe, it is placed in the cell, and the program recursively moves on to the next unassigned location. If all the cells are assigned and the Sudoku grid is filled, the program returns true, indicating that a solution has been found. If the program reaches a point where it cannot place any number in the current cell without violating the Sudoku rules, it backtracks and tries a different number in the previous cell.

The program includes helper functions such as `FUL` to find unassigned locations, `isSafe` to check if a number can be placed in a given row, column, or 3x3 box, and `printOUTPUT` to display the solved Sudoku grid.

## Usage
1. Update the `OUTPUT` array with the initial Sudoku grid, where 0 represents an empty cell.
2. Compile and run the program.
3. The program will output the solved Sudoku grid if a solution exists, or display "No solution exists" otherwise.

Feel free to modify the initial Sudoku grid in the `OUTPUT` array to solve different puzzles.

## Requirements
- C++ compiler

## Example
The following is an example of a Sudoku grid that can be solved using this program:

```cpp
int OUTPUT[H][H] = {
    {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0}
};
```

Output:
```
3 1 6 5 7 8 4 9 2 
5 2 9 1 3 4 7 6 8 
4 8 7 6 2 9 5 3 1 
2 6 3 4 1 5 9 8 7 
9 7 4 8 6 3 1 2 5 
8 5 1 7 9 2 6 4 3 
1 3 8 9 4 7 2 5 6 
6 9 2 3 5 1 8 7 4 
7 

4 5 2 8 6 3 1 9 
```

## License
This project is licensed under the [MIT License](LICENSE).
