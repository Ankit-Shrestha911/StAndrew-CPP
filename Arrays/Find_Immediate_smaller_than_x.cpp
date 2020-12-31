#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Optimize Method O(N);
int findSmallerThanX(int *arr, int size, int x)
{
	// First we sort the array //
	sort(arr, arr + size);
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == x)
		{	// search for x element in array if find x then return i-1 element bcz in sorted array the minimum
			// smaller than x is i-1 index element //
			return arr[i - 1];
			break;
		}
	}

	return arr[size - 1]; // if it don't found any x value in array that mean the smaller than x is size-1[index]//
}

void print(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	int arr[] = {1, 2, 15, 12, 10, 5, 14, 16}; // x = 15 ans  = 12 //
	int size = sizeof(arr) / sizeof(int);

	cout << findSmallerThanX(arr, size, 12);

	return 0;
}