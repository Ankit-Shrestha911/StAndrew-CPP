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

node* findMidElement(node* &head){
    node* temp = head;
    if(temp == NULL) return NULL;
    if(temp->next == NULL) return temp;
    node*slow = temp;
    node*fast = head->next;
    while(fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;

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
    insertAttail(head, 4);
    insertAttail(head, 5);
    insertAttail(head, 6);
    insertAttail(head, 7);
    insertAttail(head, 8);
    insertAttail(head, 9);
    insertAttail(head, 10);

    display(head);
    cout<<endl;
   node* mid =  findMidElement(head);
  cout<<"Middle element is "<<mid->data;
   

    return 0;
}