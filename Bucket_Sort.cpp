#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        next = NULL;
    }
};

Node *insertionSort(Node *head)
{
    Node *k, *current;
    if (head == 0 || head->next == 0)
    {
        return head;
    }

    current = head;
    k = head->next;
    current->next = NULL;

    while (k != NULL)
    {
        Node *ptr;
        if (current->data > k->data)
        {
            Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = current;
            current = tmp;
            continue;
        }

        for (ptr = current; ptr->next != 0; ptr = ptr->next)
        {
            if (ptr->next->data > k->data)
                break;
        }

        if (ptr->next != 0)
        {
            Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = ptr->next;
            ptr->next = tmp;
            continue;
        }
        else
        {
            ptr->next = k;
            k = k->next;
            ptr->next->next = 0;
            continue;
        }
    }
    return current;
}

void bubbleSort(Node **head)
{
    Node *current = *head, *index = NULL;
    int temp;
    while (current != NULL)
    {
        // index points to the node next to current
        index = current->next;

        while (index != NULL)
        {
            if (current->data > index->data)
            {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}

void bucketSort(int arr[], int n)
{
    Node *buckets[10];

    for (int i = 0; i < 10; i++)
    {
        buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++)
    {
        int position = arr[i] / 10;

        Node *current = new Node();
        current->data = arr[i];
        current->next = buckets[position];

        buckets[position] = current;
    }

    for (int i = 0; i < 10; i++)
    {
        // buckets[i] = insertionSort(buckets[i]);
        bubbleSort(&buckets[i]);
    }

    for (int i = 0, j = 0; i < 10; i++)
    {
        Node *node = buckets[i];

        while (node != NULL)
        {
            arr[j++] = node->data;
            node = node->next;
        }
    }

    // free Linked Lists
    for (int i = 0; i < 10; ++i)
    {
        struct Node *node;
        node = buckets[i];
        while (node)
        {
            struct Node *tmp;
            tmp = node;
            node = node->next;
            free(tmp);
        }
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
    int a[] = {42, 32, 33, 52, 37, 47, 51, 15, 13, 12};
    int n = 10;

    cout << "Initial array: " << endl;
    printArr(a, n);

    bucketSort(a, n);

    cout << "Sorted array: " << endl;
    printArr(a, n);

    return 0;
}