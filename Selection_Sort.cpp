#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n-1 ; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }
        }
        swap(a[i], a[min]);
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
    int a[] = {4, 2, 6, 1, 7, 2, 8};
    int n = 7;
    
    selectionSort(a, n);

    printArr(a, n);

    return 0;
}