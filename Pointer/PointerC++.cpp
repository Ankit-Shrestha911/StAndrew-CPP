#include <iostream>

//        Pointer       //

using namespace std;

int main()
{
  int x = 4;
  int *p = &x;
  int **pp = &p;
  cout << endl
       << "      Pointer" << endl;
  cout << "Address of Single pointer: " << p << endl;
  cout << "Address of Double pointer: " << *pp << endl;
  cout << "Address of X: " << &x << endl
       << endl;

  cout << "     Values" << endl;
  cout << "Value of single pointer: " << *p << endl;
  cout << "Value of Double pointer: " << **pp << endl;
  cout << "Value of X: " << x << endl
       << endl;

  cout << "   Pointer Own Address" << endl;
  cout << "Single pointer own Address: " << &p << endl;
  cout << "Double pointer own Address: " << &pp << endl<<endl;


  // Change the value of x using single pointer //
  *p = 5;
  cout<<"New value of x: "<<x<<endl<<endl;
  
  // Change the value of x using double pointer //
  **pp = 6;
  cout<<"New value of x: "<<x<<endl<<endl;

  cout<<"Address p : "<<&p<<endl;

  cout<<"Address containg of p: "<<pp;

  return 0;
}