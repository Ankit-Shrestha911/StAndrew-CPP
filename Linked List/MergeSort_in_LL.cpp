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

node *mergeLL(node *head, node *head1)
{
    // base case//
    if (head == NULL)
    {
        return head1;
    }

    // base case //
    if (head1 == NULL)
    {
        return head;
    }

    // recursive case //
    node *a;
    if (head->data < head1->data)
    {
        a = head;
        a->next = mergeLL(head->next, head1);
    }
    else
    {
        a = head1;
        a->next = mergeLL(head, head1->next);
    }

    return a;
}

node *mid(node *head)
{
   
    node *fast = head->next;
    node *slow = head;

    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

node *mergeSort(node *head)
{
    // base case //
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    //Divide the list //
    node *middle = mid(head);
    node *head1 = middle->next;
    middle->next = NULL;

    //recursive case //
    head = mergeSort(head);
    head1 = mergeSort(head1);

    // Merge the sorted two linked list //
    node *newHead = mergeLL(head, head1);

    return newHead;
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
    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int data;
        cin >> data;
        insertAtEnd(head, data);
    }
    node *ans = mergeSort(head);
    display(ans);

    return 0;
}