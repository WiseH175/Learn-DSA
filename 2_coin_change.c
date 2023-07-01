#include <stdio.h>
// denomination[] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000 };
// amount = 93

void func(int deno[], int amount, int n){
    for(int i = n-1;i >= 0;i--){
        while(amount >= deno[i]){
            amount -= deno[i];
            printf("%d ", deno[i]);
        }
    }
}

int main(){
    int n;
    printf("Enter: ");
    scanf("%d", &n);

    int deno[n]; // denomination array...sort it if its not
    for(int i = 0;i < n;i++){
        scanf("%d", &deno[i]);
    }

    int amount;
    scanf("%d", &amount);

    func(deno,amount,n);
    return 0;
}