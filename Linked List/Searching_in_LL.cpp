#include<iostream>
using namespace std; 

                    // Searching in Linked List //

class node{
     public:
     int data;
     node* next;
     node(int d){
         data = d;
         next = NULL;
     }
};

node* searching(node* head, int key){
    if(head == NULL){
        return NULL;
    }

    if(head->data == key){
        return head;
    }
    node* ans = searching(head->next,key);
    
    return ans;

}

void insertAtHead(node* &head, int d){
    node* n = new node(d);
    n->next = head;
    head = n;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
 
int main() 
{
    node* head = NULL;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    display(head);

    node* store  = searching(head,4);
    if(store){
        cout<<"Found "<<store->data;
    }
    else{
        cout<<"Not found";
    }

     
    return 0;
}