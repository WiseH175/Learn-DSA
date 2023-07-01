#include <stdio.h>
// Input: N = 5
// arr = {40, 20, 30, 10, 30}
// Output: 26000
int func(int arr[], int n){
    int dp[n][n];

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            dp[i][j] = -1;
        }
    }

    // fill dp[i][j] = 0 when i == j
    for(int i = 0;i < n;i++){
        dp[i][i] = 0;
    }

    // filling rest values
    for(int i = n-1;i >= 0;i--){
        for(int j = i+1; j < n;j++){
            int mini = 1e9;

            for(int k = i;k < j;k++){
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                if(steps < mini){
                    mini = steps;
                }
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][n-1];
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0;i < n;i++){
        scanf("%d", &arr[i]);
    }
    
    

    printf("%d", func(arr,n));
}