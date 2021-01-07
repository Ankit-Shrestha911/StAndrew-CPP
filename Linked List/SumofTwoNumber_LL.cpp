#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertAtHead(node *&head, int d)
{
    node *n = new node(d);
    if (head == NULL)
    {
        head = n;
        return;
    }

    n->next = head;
    head = n;
}

node *SumofTwoLL(node *a, node *b)
{
    node *temp = NULL;
    int carry = 0, sum;
    while (a != NULL || b != NULL)
    {
        sum = 0;
        if (a != NULL)
        {
            sum += a->data;
            a = a->next;
        }

        if (b != NULL)
        {
            sum += b->data;
            b = b->next;
        }
        sum += carry;
        carry = sum / 10;
        sum = sum % 10;
        insertAtHead(temp, sum);
    }
    if (carry != 0)
    {
        insertAtHead(temp, carry);
    }

    return temp;
}

void display(node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node *a = NULL, *b = NULL;
    int size1, size2;
    cin >> size1 >> size2;

    for (int i = 0; i < size1; i++)
    {
        int data;
        cin >> data;
        insertAtHead(a, data);
    }
    for (int i = 0; i < size2; i++)
    {
        int data;
        cin >> data;
        insertAtHead(b, data);
    }
    node *ans = SumofTwoLL(a, b);
    display(ans);

    return 0;
}