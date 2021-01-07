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

int length(node* head){ // Calculating the length //

    int cnt = 0;
    while(head){
    cnt++;
    head = head->next;
    }
    return cnt;
}

void insertAtTail(node *&head, int d) // inserting the node from tail //
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




void deleteLLHead(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteEnd(node *&head)
{
    if (head == NULL)
        return;
    node *temp = head;
    int cnt = 1;
    while (cnt < length(head) - 1)
    {
        temp = temp->next;
        cnt++;
    }
    node *todelete = temp->next;
    temp->next = NULL;
    delete todelete;
}


void deleteAtmid(node* &head, int pos ){
    if(pos == 0){
        deleteLLHead(head);
        return;
    }
    if(pos>=length(head)){
        deleteEnd(head);
        return;
    }
    else{
        int cnt =1;
        node* temp = head;
        while(cnt<=pos-1){
            temp = temp->next;
           
            cnt++;
        }
        node*x = temp->next;
        temp->next = x->next;
        delete x;
    }
}
void display(node *head) // Traversing  linked list //
{
    node *temp = head;
    while (temp)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    cout<<endl;
    deleteAtmid(head,1);
    display(head);
   

    return 0;
}