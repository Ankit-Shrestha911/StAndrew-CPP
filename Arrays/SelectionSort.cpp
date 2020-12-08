#include<iostream>
using namespace std;

// Selection Sort //

void selectionSort(int *arr, int size){

    for (int i = 0; i < size-1; i++)
    {
        int min = i;
        for (int j = i; j < size; j++)
        {
            if(arr[j]<arr[min]){ // same as bubble sort the diff is only the swapping is outside the inner loop  
                min = j;
            }
            

        }

        swap(arr[i],arr[min]); // iterate all element and find the min from the array and swap the first [i] index with 
        // minimum value index [j] //
        
    }
    
}
 
int main() 
{
      int arr[] = {10,9,3,1,0,5,6,-1};
    int size = sizeof(arr)/sizeof(int);

    selectionSort(arr,size); // Calling the function //

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}