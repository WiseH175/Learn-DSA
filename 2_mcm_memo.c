#include <stdio.h>
// Input: N = 5
// arr = {40, 20, 30, 10, 30}
// Output: 26000
int func(int arr[], int n, int i, int j,int dp[n][n]){
    if(i == j){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int mini = 1e9;
    for(int k = i;k < j;k++){
        int steps = arr[i-1]*arr[k]*arr[j] + func(arr,n,i,k,dp) + func(arr,n,k+1,j,dp);
        if(mini > steps){
            mini = steps;
        }
    }

    dp[i][j] = mini;
    return mini;
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0;i < n;i++){
        scanf("%d", &arr[i]);
    }
    
    int dp[n][n];

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            dp[i][j] = -1;
        }
    }

    printf("%d", func(arr,n, 1, n-1,dp));
}