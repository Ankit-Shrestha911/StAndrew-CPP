#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//   Sieve of Eratosthenes  //

void prime(int n)
{
    vector<bool> primeNumber(n + 1, true);

    for (int i = 2; i <= sqrt(n); i++)
    {
        for (int j = i * i; j <= n; j += i)
        {
            primeNumber[j] = false;
        }
    }

    cout << "Prime: ";
    for (int i = 2; i <= n; i++)
    {
        if (primeNumber[i])
        {
            cout << i << " ";
        }
    }
}
int main()
{
    int n;
    cin >> n; // Enter the range of number to check for prime //
              // Like you enter 10 ---> output show --> 2 3 5 7 these number are prime the enter range (10)//

    prime(n); //

    return 0;
}