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

void sortHelper(node*&temp,node*&tempd, node*&head){

    if(temp == NULL){
        temp = head;
        head = head->next;
        tempd = temp;
        tempd->next = NULL;
    }
    else{
        tempd->next  = head;
        head = head->next;
        tempd = tempd->next;
        tempd->next = NULL;
    }


}


node* sortList(node*&head){
    node*z=NULL,*zd=NULL,*o=NULL,*od=NULL,*t=NULL,*td=NULL;

    if(head->data == 0){
       sortHelper(z,zd,head);
    }
    else if(head->data == 1){
           sortHelper(o,od,head);
    }
    else{
            sortHelper(t,td,head);
    }

    if(zd!=NULL){
        zd->next = o;
        head = z;
    }

    if(od!=NULL){
        od->next = t;
        if(o!=NULL and z==NULL){
                  head = o;
        }
    }

    if(!o and !z){
        head  = t;
    }

    return head;

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
    node *head = NULL;
    int size1;
    cin >>size1;

    for (int i = 0; i < size1; i++)
    {
        int data;
        cin >> data;
        insertAtEnd(head, data);
    }
   
node*ans = sortList(head);
    display(ans);

    return 0;
}