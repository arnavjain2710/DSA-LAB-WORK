#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int value;
    Node *left , *right;
    int height;
};

Node* newNode(int key)
{
    Node* node = new Node();
    node->value = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; 
    return(node);
}

int heightNode(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(heightNode(y->left),heightNode(y->right)) + 1;
    x->height = max(heightNode(x->left), heightNode(x->right)) + 1;
    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(heightNode(x->left),heightNode(x->right)) + 1;
    y->height = max(heightNode(y->left),heightNode(y->right)) + 1;
    return y;
}

int BalanceFactor(Node *N)
{
    if (N == NULL)
        return 0;
    return heightNode(N->left) - heightNode(N->right);
}

void preOrder(Node *root)
{
    if(root != NULL)
    {
        cout << root->value << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

Node* insert(Node* node, int key)
{
    if (node == NULL)
    {
        return(newNode(key));
    }
 
    if (key < node->value)
        node->left = insert(node->left, key);
    else if (key > node->value)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(heightNode(node->left),heightNode(node->right));
 
    int balance = BalanceFactor(node);
 
    // Left Left Case
    if (balance > 1 && key < node->left->value)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->value)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->value)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->value)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    return node;
}

Node * minValueNode(Node* node)
{
    Node* current = node;

    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 
Node* deleteNode(Node* root, int key)
{
    if (root == NULL)
        return root;

    if ( key < root->value)
        root->left = deleteNode(root->left, key);
 
    else if( key > root->value )
        root->right = deleteNode(root->right, key);
 
    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            Node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp; 
            }
            free(temp);
        }
        else
        {
            Node* temp = minValueNode(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }
    if (root == NULL)
    {
        return root;
    }
    root->height = 1 + max(heightNode(root->left),heightNode(root->right));
 
    int balance = BalanceFactor(root);

    // LL Case
    if (balance > 1 && BalanceFactor(root->left) >= 0)
        return rightRotate(root);
 
    // LR Case
    if (balance > 1 && BalanceFactor(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    // RR Case
    if (balance < -1 && BalanceFactor(root->right) <= 0)
        return leftRotate(root);
 
    // RL Case
    if (balance < -1 && BalanceFactor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}

int main()
{
    Node *root = NULL;
    for(int i=1;i<=16;i++)
    {
        root = insert(root,i);
    }
    cout<<"The preorder traversal of the AVL tree is "<<endl;
    preOrder(root);
    cout<<endl;
    cout<<"The preorder traversal of the AVL tree after the deletetion of 8 is:"<<endl;
    root = deleteNode(root , 8);
    preOrder(root);
    cout<<endl;
    return 0;
}