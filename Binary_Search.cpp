#include <iostream>
using namespace std;

int binary_search(int arr[], int key, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }

        if (arr[mid] < key)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }

    return -1;
}
int main()
{
    int n, key, result;
    cout << "Enter Number of elements in array: ";
    cin >> n;

    int arr[n];

    cout << "Enter Integers: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter Element to search: ";
    cin >> key;

    result = binary_search(arr, key, 0, n - 1);

    if (result == -1)
    {
        cout << "Element not present";
    }
    else
    {
        cout << "Element is present at location " << result+1;
    }

    return 0;
}