#include <iostream>
using namespace std;
// Insertion Sort //

void insertionSort(int *arr, int size){

  int min,j;
    for (int i = 1; i < size; i++)
    {
        min = arr[i];
        j = i;

        while(j>=0 and arr[j-1]>min){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = min;
    }
    
}
int main()
{

    int arr[] = {10, 9, 3, 1, 0, 5, 6, -1};
    int size = sizeof(arr) / sizeof(int);

    insertionSort(arr, size); // Calling the function //

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}