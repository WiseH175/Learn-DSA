#include <stdio.h>
// Input: start[]  =  {10, 12, 20}, finish[] =  {20, 25, 30}
// Output: 0 2


void func(int s[], int f[], int n){
    int i = 0;

    printf("Activity %d\n", i+1);

    for(int j = 1;j < n;j++){
        if(s[j] >= f[i]){
            printf("Activity %d\n", j+1);
            i = j;
        }
    }

    return;
}

int main(){
    int n;
    scanf("%d", &n);

    int s[n];
    for(int i = 0;i < n;i++){
        scanf("%d", &s[i]);
    }

    int f[n];
    for(int i = 0;i < n;i++){
        scanf("%d", &f[i]);
    }

    func(s,f,n);
    return 0;
}