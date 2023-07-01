#include <stdio.h>
#include <limits.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int solve(int price[], int ind, int len)
{
    if (ind == 0)
    {
        return price[ind] * len;
    }

    int notPick = 0 + solve(price, ind - 1, len);
    int pick = INT_MIN;

    int rod_length = ind + 1;

    if (len >= rod_length)
    {
        pick = price[ind] + solve(price, ind, len - rod_length);
    }

    return max(pick, notPick);
}

int solve2(int price[], int n, int len)
{
    int dp[n][len + 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < len+1; j++)
        {
            if(i == 0)
            {
                dp[i][j] = price[i] * (j);
                continue;
            }


            int nP = 0 + dp[i-1][j];
            int rodL = i + 1;

            int P = 0;

            if(j >= rodL)
            {
                P = price[i] + dp[i][j-rodL];
            }

            dp[i][j] = max(nP, P);
        }
    }

    return dp[n-1][len];
}

int main()
{
    printf("Enter the length of rod \n");
    int n;
    scanf("%d", &n);
    int prices[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &prices[i]);
    }

    int dp[n][n + 1];

    printf("The max profit is : %d \n", solve(prices, n - 1, n));
    printf("The max profit is : %d \n", solve2(prices, n, n));
}