#include <stdio.h>
#include <stdlib.h>

struct Item
{
    double value;
    double weight;
};

int cmp(const void *a, const void *b)
{
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    double ratio1 = item1->value / item1->weight;
    double ratio2 = item2->value / item2->weight;
    // if (ratio1 < ratio2)
    // {
    //     return 1;
    // }
    // else if (ratio1 > ratio2)
    // {
    //     return -1; 
    // }
    // else
    // {
    //     return 0;
    // }

    return ratio1 - ratio2;
}

double fractionalKnapsack(int W, struct Item arr[], int n)
{
    int i;
    double max_ratio, profit = 0;

    for (i = 0; i < n; i++)
    {
        if (arr[i].weight <= W)
        {
            profit += arr[i].value;
            W -= arr[i].weight;
        }
        else
        {
            max_ratio = arr[i].value / arr[i].weight;
            profit += max_ratio * W;
            W = 0;
            break;
        }
    }

    return profit;
}

int main()
{
    int W = 60;
    struct Item arr[] = {{30, 10}, {180, 30}, {100, 20}};
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(struct Item), cmp);

    double profit = fractionalKnapsack(W, arr, n);
    printf("Maximum profit: %f", profit);

    return 0;
}
