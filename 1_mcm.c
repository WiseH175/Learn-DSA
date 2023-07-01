#include <stdio.h>

int func(int arr[], int n, int i, int j){
    if(i == j){
        return 0;
    }

    int mini = 1e9;
    for(int k = i;k < j;k++){
        int steps = arr[i-1]*arr[k]*arr[j] + func(arr,n,i,k) + func(arr,n,k+1,j);
        if(mini > steps){
            mini = steps;
        }
    }
    return mini;
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0;i < n;i++){
        scanf("%d", &arr[i]);
    }

    printf("%d", func(arr,n, 1, n-1));
}