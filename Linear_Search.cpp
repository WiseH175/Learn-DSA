#include <iostream>
using namespace std;

int linear_search(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i + 1;
        }
    }

    return -1;
}
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

    int key, result;

    cout << "Enter Element to search: ";
    cin >> key;

    result = linear_search(arr, n, key);

    if (result == -1)
    {
        cout << "Element not present";
    }
    else
    {
        cout << "Element is present at location " << result;
    }

    return 0;
}