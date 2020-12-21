#include <iostream>
using namespace std;

// Searching in Linked List //

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

int lenght(node *head)
{
    int cnt = 0;
    while (head)
    {

        cnt++;
        head = head->next;
    }

    return cnt;
}

void insertAtHead(node *&head, int d)
{
    node *n = new node(d);
    n->next = head;
    head = n;
}

void insertAttail(node *&head, int d)
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

void insertAtMid(node *&head, int d, int pos)
{
    if (pos == 0)
    {
        insertAtHead(head, d);
    }
    else if (pos >= lenght(head))
    {
        insertAttail(head, d);
    }
    else
    {
        node *temp = head;
        int count = 1;
        while (count <= pos - 1)
        {
            temp = temp->next;
            count++;
        }
        node *n = new node(d);
        n->next = temp->next;
        temp->next = n;
    }
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    // insertAtHead(head,1);
    // insertAtHead(head,2);
    // insertAtHead(head,3);
    // display(head);
    insertAttail(head, 1);
    insertAttail(head, 2);
    insertAttail(head, 3);
    display(head);
    insertAtMid(head,4,2);
    display(head);

    return 0;
}