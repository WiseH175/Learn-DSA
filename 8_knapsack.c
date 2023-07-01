#include <stdio.h>
#include <limits.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int func1(int val[], int wt[], int ind, int w)
{
    // recursive function
    if (ind == 0)
    {
        return wt[ind] <= w ? val[ind] : 0;
    }

    int notPick = func1(val, wt, ind - 1, w);
    int pick = INT_MIN;

    if (w - wt[ind] >= 0)
    {
        pick = val[ind] + func1(val, wt, ind - 1, w - wt[ind]);
    }

    return max(pick, notPick);
}

int func2(int val[], int wt[], int n, int ind, int w, int dp[n][w + 1])
{
    // meomisation function
    if (ind == 0)
    {
        return wt[ind] <= w ? val[ind] : 0;
    }

    if (dp[ind][w] != -1)
    {
        return dp[ind][w];
    }
    int notPick = func2(val, wt, n, ind - 1, w, dp);
    int pick = INT_MIN;

    if (w - wt[ind] >= 0)
    {
        pick = val[ind] + func2(val, wt, n, ind - 1, w - wt[ind], dp);
    }

    dp[ind][w] = max(pick, notPick);

    return dp[ind][w];
}

int func3(int val[], int wt[], int n, int w)
{
    int dp[n][w + 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0)
            {
                if (wt[i] <= j)
                {
                    dp[i][j] = val[i];
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
            else
            {
                int notPick = dp[i - 1][j];
                int pick = INT_MIN;

                if (j - wt[i] >= 0)
                {
                    pick = val[i] + dp[i - 1][j - wt[i]];
                }

                dp[i][j] = max(pick, notPick);
            }
        }
    }

    return dp[n - 1][w];
}

int main()
{
    int n;
    printf("Enter the value of items\n");
    scanf("%d", &n);

    int val[n];
    int wt[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the value ans weight \n");
        scanf("%d", &val[i]);
        scanf("%d", &wt[i]);
    }

    int w;
    printf("Enter the value of knapsack\n");
    scanf("%d", &w);

    int dp[n][w + 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = -1;
        }
    }

    printf("%d \n", func1(val, wt, n - 1, w));
    printf("%d \n", func2(val, wt, n, n - 1, w, dp));
    printf("%d \n", func3(val, wt, n, w));
}