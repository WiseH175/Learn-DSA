#include <stdio.h>
#include <stdbool.h>

int board[9][9];

void print_board(int board[9][9])
{
    printf("\nSolution: \n");
    int i, j;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool is_valid(int board[9][9], int row, int col, int c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == c)
            return false;

        if (board[row][i] == c)
            return false;

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}

bool solve(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                for (int c = 1; c <= 9; c++)
                {
                    if (is_valid(board, i, j, c))
                    {
                        board[i][j] = c;

                        if (solve(board) == true)
                        {
                            print_board(board);
                            return true;
                        }
                        else
                            board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    print_board(board);
    return true; // both for loops ran, no empty cell, works like base case
}

int main()
{
/*
2 5 6 4 0 3 9 8 1
3 0 9 8 5 1 2 7 6
8 7 1 9 2 6 4 3 5
4 2 7 0 6 8 1 9 3
9 1 5 3 4 2 8 6 7
6 8 3 1 9 7 0 2 4
5 9 8 7 3 4 6 1 2
0 3 2 6 8 5 7 4 9
7 6 4 2 1 9 3 5 0
*/


    int i, j;
    printf("Enter the Sudoku board (use 0 for empty cells):\n");

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    solve(board);

    return 0;
}
