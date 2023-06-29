
#include <bits/stdc++.h>
using namespace std;
#define UNASSIGNED 0
#define H 9

//FUL= FINDING THE UNASSIGNED LOCATION
bool FUL(int grid[H][H],
                            int& row, int& col);
                            
//assigning num to given row and col
bool isSafe(int grid[H][H], int row,
            int col, int num);
bool Sudokugamesolver(int grid[H][H])
{
    int row, col;
    if (!FUL(grid, row, col))
        return true;
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (Sudokugamesolver(grid))
                return true;
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}
bool FUL(int grid[H][H],
                            int& row, int& col)
{
    for (row = 0; row < H; row++)
        for (col = 0; col < H; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}
bool UsedInRow(int grid[H][H], int row, int num)
{
    for (int col = 0; col < H; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
bool UsedInCol(int grid[H][H], int col, int num)
{
    for (int row = 0; row < H; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
bool UsedInBox(int grid[H][H], int boxStartRow,
               int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow]
                    [col + boxStartCol] ==
                                       num)
                return true;
    return false;
}
bool isSafe(int grid[H][H], int row,
            int col, int num)
{
    return !UsedInRow(grid, row, num)
           && !UsedInCol(grid, col, num)
           && !UsedInBox(grid, row - row % 3,
                         col - col % 3, num)
           && grid[row][col] == UNASSIGNED;
}
void printOUTPUT(int OUTPUT[H][H])
{
    for (int row = 0; row < H; row++)
    {
        for (int col = 0; col < H; col++)
            cout << OUTPUT[row][col] << " ";
        cout << endl;
    }
}

//main function
//unassigned cells are 0
//matrix representation
int main()
{
    int OUTPUT[H][H] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    if (Sudokugamesolver(OUTPUT) == true)
        printOUTPUT(OUTPUT);
    else
        cout << "No solution exists";
 
    return 0;
}

