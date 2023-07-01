#include <iostream>
using namespace std;

int hs = 7;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void max_heapify(int arr[], int i)
{
    int Lc_index = 2 * i + 1;
    int Rc_index = 2 * i + 2;
    int largest = i;

    if (Lc_index < hs && arr[Lc_index] > arr[i])
        largest = Lc_index;

    if (Rc_index < hs && arr[Rc_index] > arr[largest])
        largest = Rc_index;

    if (largest != i)
    {
        swap(arr[i],arr[largest]);
        max_heapify(arr, largest);
    }
}

void build_maxHeap(int arr[])
{
    int t = hs / 2 - 1;
    for (int i = t; i >= 0; i--)
        max_heapify(arr, i);
}

void heap_sort(int arr[], int n)
{
    build_maxHeap(arr);

    int t = hs;
    int t1 = hs - 1;

    for (int i = t1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        hs--;
        max_heapify(arr, 0);
    }
    hs = t;
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {5, 4, 2, 3, 1, 7, 8};
    int n = sizeof(arr) / sizeof(int);

    heap_sort(arr, n);

    print_array(arr, n);
    return 0;
}