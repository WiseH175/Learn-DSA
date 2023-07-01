#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Bubble sort
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

int main()
{
    int n = 10000, i = 10;
    while (i--)
    {
        int arr[n];
        
        
        for (int i = 0; i < n; i++)          //Best
        {
            arr[i] = i;
        }
        time_t start = clock();
        bubbleSort(arr, n);
        time_t end = clock();
        printf("%d \t %f ", n, (double)(end - start)/CLOCKS_PER_SEC);
        
        for (int i = 0; i < n; i++)      //Average
        {
            arr[i] = rand() % n + 1;
        }
        start = clock();
        bubbleSort(arr, n);
        end = clock();
        printf("\t %f ", (double)(end - start)/CLOCKS_PER_SEC);
        
        
        
        for (int i = 0; i < n; i++)             // Worst case
        {
            arr[i] = n-i;
        }
        start = clock();
        bubbleSort(arr, n);
        end = clock();
        printf("\t %f \n", (double)(end - start)/CLOCKS_PER_SEC);
        
        n += 10000;
    }
    return 0;
}

/*
 plot './data.txt' using 1:2 title 'Best' with linespoints, './data.txt' using 1:3 with linespoints, './data.txt' using 1:4 with linespoints
 */
