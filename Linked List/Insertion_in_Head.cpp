#include <iostream>
using namespace std;

                                  // Linked List //
                     //Insertion at head and Insertion in tail //

class node
{
public:
    int data;
    node *next; // pointer //
    node(int d) // Parameter constructor //
    {
        data = d;
        next = NULL;
    }
};

void insertInTail(node *&head, int d)
{
    node *n = new node(d); // n is containing the address of node //
    if (head == NULL) // if we have head is null that is we have no value in the Linked list so, we put the n to head //
    // that mean our first node is head //
    {
        head = n;
        return;
    }
    node *temp = head; // In a safe side i create this temp variable to store the head bcz we dont want to lose the head//
    //If we lose head that is we lose all the linked list data //
    while (temp->next != NULL)  //
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertInHead(node *&head, int d)
{
   // Method 1 //

    // node *n = new node(d);
    // // n->data = d;
    // n->next = head;
    // head = n;

    // Method 2 //
    if (head == NULL)
    // if we have head is null that is we have no value in the Linked list so, we put the n to head //
    // that mean our first node is head //
    {
        node *n = new node(d);
        head = n;
    }
    else
    {
        node *n = new node(d);
        n->next = head;
        head = n;
    }
}

void display(node *head)
{
    node *temp = head; // In a safe side to create temp variable //
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL, *tail = NULL;
    // Insertion in head //
    cout<<"Head Insertion"<<endl;
    insertInHead(head, 1);
   
    display(head);
    insertInHead(head, 5);
    display(head);
    insertInHead(head, 10);
    display(head);

    // Insertion in tail //
        cout<<"Tail Insertion"<<endl;

    insertInTail(head,1);
    insertInTail(head,2);
    insertInTail(head,3);
    display(head);
    return 0;
}