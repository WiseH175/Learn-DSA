#include <iostream>
using namespace std;

void shellSort(int a[], int n)
{
    int intv = n / 2;

    while (intv)
    {
        for (int i = intv; i < n; i++)
        {
            int key = a[i];
            int j = i - intv;

            while (j >= 0 && key < a[j])
            {
                a[j + intv] = a[j];
                j = j - intv;
            }

            a[j + intv] = key;
        }

        intv = intv / 2;
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
    int a[] = {4, 2, 6, 1, 7, 2, 9, 11};
    int n = 8;
    
    shellSort(a, n);

    printArr(a, n);

    return 0;
}