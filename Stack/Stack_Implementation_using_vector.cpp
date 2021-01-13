#include <iostream>
#include <vector>
using namespace std;

//Stack using vector //
class stack
{
    vector<int> s;

public:
    void push(int d)
    {
        s.push_back(d);
        // s.insert(s.begin(),d); // alternative way //
    }

    int top()
    {
        return s[s.size() - 1];
        // return s[0]; if we use the above alternative way then we use this //
    }
    void pop()
    {
        s.pop_back();
        // s.erase(s.begin()) // same if we use alternative way //
    }
    bool empty()
    {
        return s.size() == 0; // this is same on the both method //
    }
};

void displayStack(stack s)
{ // we create displayStack function to overcome the once print the stack ///
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main()
{
    stack s;

    for (int i = 0; i <= 5; i++)
    {
        s.push(i + 1);
    }

    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);

    // if we use this we can  only print the stack list once because we pop the stack that's why our stack
    // is empty because it affect the original stack //
    // If you want to print the stack list again again create printStack function to resolve this issue //
    // while (!s.empty())
    // {

    // 	cout << s.top() << " ";
    // 	s.pop();
    // }

    displayStack(s); // display the element in the stack 6 5 4 3 2 1 //
    s.pop();         // remove one element from top mean front  //
    displayStack(s); // after pop remaining element is 5 4 3 2 1 //

    return 0;
}