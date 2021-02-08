#include <bits/stdc++.h>
using namespace std;
#define MAX 100

    class Stack
    {
        int top;

    public:
        int a[MAX];

        Stack()
        {
            top = -1;
        }

        void push(int x)
        {
            if (top >= MAX - 1)
            {
                cout << "Stack overflow";
            }
            else
            {
                a[++top] = x;
            }
        }

        void pop()
        {
            if (top < 0)
            {
                cout << "Underflow";
            }
            else
            {
                int x = a[top--];
            }
        }

        int peek()
        {
            if (top < 0)
            {
                cout << "Stack is empty";
                return -1;
            }

            int x = a[top];
            return x;
        }

        bool empty()
        {
            return (top < 0);
        }
    };

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    while (!s.empty())
    {
        cout << s.peek() << " ";
        s.pop();
    }

    return 0;
}