#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number of elements in array: ";
    cin >> n;

    int arr[n];

    cout << "Enter Integers: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++)                  // Bubble sort requires n-1 iterations
    {
        for (int j = 0; j < n - i - 1; j++)          // First we do n-1 iterations then i-2 then i-3, etc.
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted Array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}