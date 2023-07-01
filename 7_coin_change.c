#include <stdio.h>
#include <math.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int func(int deno[], int i, int amount)
{
    if (i == 0)
    {
        if (amount % deno[i] == 0)
        {
            return amount / deno[i];
        }
        else
        {
            return 1e9;
        }
    }

    int pick = 1e9;
    int notPick = 0 + func(deno, i - 1, amount);

    if (amount >= deno[i])
    {
        pick = 1 + func(deno, i, amount - deno[i]);
    }

    return min(pick, notPick);
}

int func2(int deno[], int n, int amount)
{
    int dp[n][amount + 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < amount+1; j++)
        {
            if(i == 0)
            {
                if(j%deno[i] == 0)
                    dp[i][j] = 1;
                else    
                    dp[i][j] = 0;
                
                continue;
            }

            int notPick = 0 + dp[i-1][amount];
            int pick = 1e9;

            if(j <= deno[i])
            {
                pick = 1 + dp[i][amount-deno[i]];
            }
        }

        return dp[n][amount + 1];
    }
}

int main()
{
    printf("Enter types of denomination\n");
    int n;
    scanf("%d", &n);
    int deno[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &deno[i]);
    }

    int amount;
    scanf("%d", &amount);

    int ans = func(deno, n - 1, amount);
    int ans2 = func(deno, n, amount);
    if (ans == 1e9)
        ans = -1;

    printf("%d \n%d", ans, ans2);
}