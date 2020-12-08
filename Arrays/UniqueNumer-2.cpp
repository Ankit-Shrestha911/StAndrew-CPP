#include <iostream>
#include <cmath>
using namespace std;

// Unique Number - 2 //

int main()
{
    int arr[100];
    int n;
    cin >> n; // 4 //
    int originalAns = 0, copyAns1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // 3 1 2 1 //
        originalAns ^= arr[i];  //originalAns = 1//   // Take XOR of all array element and store in originalAns // 
    }

    copyAns1 = originalAns; //copy the originalAns because we want to find first "1" bit in originalAns //

    int bitcounter = 0;
    while (originalAns)
    {
        if (originalAns & 1 == 1)
        {
            break;
        }

        bitcounter++;
        originalAns = originalAns >> 1; // Using right shift operator to shift 1 bit from the right //
        // for example 010>>1 means --> 001 again right shift --> 000 if originalAns value is zero the while loop is end //
    }

    int value = pow(2, bitcounter); // 2 //
    int firstNumber = 0, secondNumber = 0;

    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & value) == 0)
        {
            firstNumber ^= arr[i]; // 2 //  // Only store the which value while taking arr[i] & with value is 0;
        }
    }

    secondNumber = firstNumber ^ copyAns1; // 3 // // Storing the Xor of firstnumber and copyAns //

    cout << firstNumber << " and " << secondNumber; // 2 and 3 //

    return 0;
}