// Question 2
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left , *right;
    int value;
    Node(int x)
    {
        value=x;
        left=NULL;
        right = NULL;
    }
};

int search(int arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return 0;
}

Node* buildTree(int in[], int pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;
 
    if (inStrt > inEnd)
    {
        return NULL;
    }
 
    Node* tNode = new Node(pre[preIndex++]);

    if (inStrt == inEnd)
    {
        return tNode;
    }
    int inIndex = search(in, inStrt, inEnd, tNode->value);
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
 
    return tNode;
}

void printInorder(Node* node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout<<node->value<<" ";
    printInorder(node->right);
}

int main()
{
    int in[] = { 1,3,4,5,8,9 };
    int pre[] = { 5,3,1,4,8,9 };
    int len = sizeof(in) / sizeof(in[0]);
    Node* root = buildTree(in, pre, 0, len - 1);
 
    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
    return 0;
}