#include<iostream>
using namespace std;
 // Bubble Sort //

 void bubbleSort(int *arr ,int size){

     for (int i = 0; i < size-1; i++)
     {
         for (int j = 0; j < size-1-i; j++)
         {
             if(arr[j]>arr[j+1]){ // for ascending order // for descending if (arr[j]<arr[j+1]){swap(arr[j],arr[j+1])} // 
                 swap(arr[j],arr[j+1]);
             }
         }
         
     }
     
 }
int main() 
{
    int arr[] = {10,9,3,1,0,5,6};
    int size = sizeof(arr)/sizeof(int);

    bubbleSort(arr,size); // Calling the function //

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
     
    return 0;
}