#include <iostream>
#include <queue>

using namespace std;

class node
{
public:
    int data;
    node *left, *right;

    node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
/*
  Printing the  node of each level...
  We implement using queue, here we create queue which store node pointer.
  1. First, We have to push the root in the queue and then NULL;

  2. While our queue is not empty we have to do some task...
     create a node (i create a temp node) and assign the queue front value which store the
    (first root address) in my case root is (2).

  3. And, We don't want, root address anymore, so we pop the root from the queue.

  4. Here is, if temp is not null which means there is some value, so we print that value
     And check for left and right child of root node is exist or not, if yes 
     (if left and right child is not null which means node exist) ,
     then we also push that both left and right node.

  5. Last point (else if) if temp is null and queue is not empty which is some 
     value inside the queue, soo we push the null because we want to print all the
     value until the queue is not empty or if queue totally empty so we stop the process
     and exit from the while loop. 
*/
void tree(node *root)
{

    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp != NULL)
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

/*
                            Binary Tree

                           2  lvl -> 0
                         /   \
                        3      5  lvl -> 1
                       / \    / \
                      4   6  9   10  lvl -> 2
                    /            / \
                  8             12  11     lvl -> 3 
                         
   */

int main()
{
    node *root = new node(2);
    root->left = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(6);
    root->left->left->left = new node(8);
    root->right = new node(5);
    root->right->left = new node(9);
    root->right->right = new node(10);
    root->right->right->left = new node(12);
    root->right->right->right = new node(11);

    tree(root);
    return 0;
}