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

node *mergeLinkedList(node *a, node *b)
{
    node *dummy;

    if (a == NULL)
    {
        return b;
    }

    if (b == NULL)
    {
        return a;
    }

    if (a->data < b->data)
    {
        dummy = a;
        dummy->next = mergeLinkedList(a->next, b);
    }
    else
    {
        dummy = b;
        dummy->next = mergeLinkedList(a, b->next);
    }

    return dummy;
}

void insertAtEnd(node *&head, int d)
{
    node *n = new node(d);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
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
    node *list = NULL, *list1 = NULL;
    int size1, size2;
    cin >> size >> size1;

    for (int i = 0; i < size1; i++)
    {
        int data;
        cin >> data;
        insertAtEnd(list, data);
    }
    for (int i = 0; i < size2; i++)
    {
        int data;
        cin >> data;
        insertAtEnd(list1, data);
    }

    node *head = mergeLinkedList(list, list1);
    display(head);

    return 0;
}