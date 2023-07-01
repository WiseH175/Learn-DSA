#include <stdio.h>
#include <string.h>
#include <math.h>
// s = "waxy" t = "abcdy"
int func(char *s, char *t, int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (s[0] == t[0])
    {
        int a = func(s + 1, t + 1, m - 1, n - 1);
        return 1 + a;
    }
    else
    {
        int x = func(s + 1, t, m - 1, n);
        int y = func(s, t + 1, m, n - 1);
        int z = func(s + 1, t + 1, m - 1, n - 1);

        int ans = x;

        if (y > x && y > z)
        {
            ans = y;
        }
        if (z > y && z > x)
        {
            ans = z;
        }

        return ans;
    }
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

    printf("%d", func(s, t, m, n));
}