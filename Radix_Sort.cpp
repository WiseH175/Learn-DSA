#include <iostream>
using namespace std;

void countSort(int arr[], int n, int place)
{
    const int k = 10;
    int output[n];

    int count[k] = {0};

    // calculating count
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / place) % 10]++;
    }

    // cumulative count
    for (int i = 1; i < k; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[(arr[i] / place) % 10]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n)
{
    int k = arr[0];
    for (int i = 1; i < n; i++)
    {
        k = max(k, arr[i]);
    }

    for (int place = 1; k / place > 0; place *= 10)
    {
        countSort(arr, n, place);
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
    int a[] = {121, 432, 564, 23, 1, 45, 788};

    int n = 7;

    radixSort(a, n);

    printArr(a, n);

    return 0;
}