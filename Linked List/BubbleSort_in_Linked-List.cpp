#include<iostream>
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

void insertAtHead(node *&head, int d) // Inserting the node from head //
{
    if (head == NULL)
    {
        node *n = new node(d);
        head = n;
        return;
    }
    else
    {
        node *n = new node(d);
        n->next = head;
        head = n;
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

void bubbleSort(node* &head){
    node*prev = NULL,*current = head, *n;
    int len = length(head);

    for(int i=0; i<len-1; i++){
        current = head,prev = NULL;
       
        while(current!=NULL && current->next!=NULL){
            n = current->next;
            if(current->data > n->data){

             if(prev == NULL){
                // Head swapping //
                current->next = n->next;
                n->next  = current;
                head = prev = n;
             }
             else{
                 //Head is not swapping //
                 prev->next = current->next;
                 current->next = n->next;
                 n->next = current;
                 prev = n;
             }
            }
            else{
                prev = current;
                current = current->next;

            }


        }
    }


}

 int main()  
{
    node* head = NULL;
   int data;
   for(int i=0; i<5; i++){
       cin>>data;
       insertAtTail(head,data);
   }
    display(head);
    cout<<endl;
    bubbleSort(head);
    display(head);

     
    return 0;
}