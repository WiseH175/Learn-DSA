#include <stdio.h>
#include <stdbool.h>

bool is_possible(int n, int board[n][n], int row, int col)
{
    int r = row;
    int c = col;

    // checking for left colums
    while (col >= 0)
    {
        if (board[row][col] == 1)
            return false;
        col--;
    }
    col = c;

    // checking for upper diagonal
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 1)
            return false;
        row--;
        col--;
    }
    row = r;
    col = c;

    // checking for lower diagonal
    while (row < n && col >= 0)
    {
        if (board[row][col] == 1)
            return false;
        row++;
        col--;
    }
}

void print(int n, int board[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void solve(int n, int board[n][n], int col)
{
    if (col == n)
    {
        print(n, board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (is_possible(n, board, row, col))
        {
            board[row][col] = 1;
            solve(n, board, col + 1);
            board[row][col] = 0;
        }
    }
}

int main()
{
    printf("Enter the size of the board\n");
    int n;
    scanf("%d", &n);

    int board[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    solve(n, board, 0);
}