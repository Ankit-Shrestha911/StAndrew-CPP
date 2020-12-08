#include <iostream>
using namespace std; 

           // Merge Sort //

void mergeArray(int *arr, int start, int end)
{
    int mid = (start + end) / 2;
    int i = start;
    int j = mid + 1;
    int k = start;

    int temp[end];

    while (i <= mid and j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= end)
    {
        temp[k++] = arr[j++];
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int *arr, int start, int end)
{

    if (start < end) 
    {
        int mid = (start + end) / 2;

        mergeSort(arr, start, mid); // Divide the array 1 part//
        mergeSort(arr, mid + 1, end); // Divid the array 2 part //
        mergeArray(arr, start, end); // Merge the both array //
    }
}

int main()
{
    int arr[] = {10, 9, 3, 1, 0, 5, 6, -1};
    int size = sizeof(arr) / sizeof(int);

    mergeSort(arr, 0, size - 1); // Calling the function //

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}