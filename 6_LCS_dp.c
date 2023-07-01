#include <stdio.h>
#include <string.h>
#include <math.h>
// s = "waxy" t = "abcdy"
int max(int a, int b)
{
    return a > b ? a : b;
}

int func(char *s, char *t, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s[i] == t[j])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i][j - 1]));
            }
        }
    }

    // for (int i = 0; i <= m; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         printf("%d", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    return dp[m][n];
}

int main()
{

    printf("Enter the length of first string\n");
    int m;
    scanf("%d", &m);

    printf("Enter the first string\n");
    char s[m];
    scanf("%s", s);

    printf("Enter the length of second string\n");
    int n;
    scanf("%d", &n);

    printf("Enter the second string\n");
    char t[n];
    scanf("%s", t);

    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }

    printf("%d", func(s, t, m, n));
}