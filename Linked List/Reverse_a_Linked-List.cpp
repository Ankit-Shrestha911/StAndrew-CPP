#include <iostream>
using namespace std;

// Reverse an Linked List elements / /

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

void ReverseAnLinkedList(node *&head)
{
    node *prev = NULL, *current = head, *nxt;

    while (current)
    {
        nxt = current->next;
        current->next = prev;
        prev = current;
        current = nxt;
    }
    head = prev;
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
    ReverseAnLinkedList(head);
    display(head);

    return 0;
}