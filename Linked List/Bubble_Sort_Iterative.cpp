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

void iterativeBubbleSort(node*head,int size){

    node*curr,*nxt;

    for(int i= size-1; i>0; i--){
        curr = head;
        for(int j=1; j<=i; j++ ){
              nxt = curr->next;
              if(curr->data > nxt->data){
                  swap(curr->data,nxt->data);
              }
              curr = nxt;
        }
    }
    

}

void insertAtEnd(node *&head, int d)
{
    node *n = new node(d);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;

}

void display(node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    node*head = NULL;
    int size;
    cin>>size;

    for(int i=0; i<size; i++){
        int data;
         cin>>data;
         insertAtEnd(head,data);
    }

    display(head);
    iterativeBubbleSort(head,size);
    display(head);



    return 0;
}