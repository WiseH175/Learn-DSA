#include <stdio.h>

void printSolution(int n, int sol[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }

    printf("\n");
}
 
void solve(int maze[4][4], int n, int vis[n][n], int i, int j)
{
    if (i == n - 1 && j == n - 1)
    {
        vis[i][j] = 1;
        printf("Solution: \n");
        printSolution(4, vis);
        vis[i][j] = 0;
        return;
    }

    // down
    if (i + 1 < n && !vis[i + 1][j] && maze[i + 1][j] == 1)
    {
        vis[i][j] = 1;
        solve(maze, n, vis, i + 1, j);
        vis[i][j] = 0;
    }

    // right
    if (j + 1 < n && !vis[i][j + 1] && maze[i][j + 1] == 1)
    {
        vis[i][j] = 1;
        solve(maze, n, vis, i, j + 1);
        vis[i][j] = 0;
    }
}

int main()
{
    int n = 4;

    int maze[4][4] = {{1, 0, 0, 0},
                      {1, 1, 0, 1},
                      {1, 1, 0, 0},
                      {1, 1, 1, 1}};
    int sol[4][4] = {{0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}};

    solve(maze, n, sol, 0, 0);

    return 0;
}