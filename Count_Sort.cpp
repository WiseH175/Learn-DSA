#include <iostream>
using namespace std;

void countSort(int arr[], int n)
{
    // find max element
    int k = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > k)
        {
            k = arr[i];
        }
    }

    // initialize each element with 0
    int count[k + 1] = {0};

    // store count of each element
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // cumulative count
    for (int i = 1; i <= k; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = {4, 2, 2, 8, 3, 3, 1};
    int n = 7;

    countSort(a, n);

    printArr(a, n);

    return 0;
}