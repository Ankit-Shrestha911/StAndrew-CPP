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
    bool visited[10001] = {false};
    node *head = NULL;

    while (true)
    {
        int data;
        cin >> data;
        if (data != -1)
        {
            if (visited[data] == true)
            {
                break;
            }
            else
            {
                insertAtEnd(head, data);
                visited[data] = true;
            }
        }
        else
        {
            break;
        }
    }

    display(head);

    return 0;
}