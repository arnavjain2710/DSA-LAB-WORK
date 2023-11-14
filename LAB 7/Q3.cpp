#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int value;
    Node *left , *right;
    int height;
 
};
Node* newNode(int x)
{
    Node* node = new Node();
    node->value = x;
    node->left = node->right = NULL;
    return node;
}
vector<int> v;
void inorder(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    v.push_back(root->value);
    inorder(root->right);
}
int main()
{
    Node *root = newNode(5);
    root->right = newNode(6);
    root->right->right = newNode(7);
    root->left = newNode(3);
    root->left->right=newNode(4);
    inorder(root);
    for(int i=0;i<v.size()-1;i++)
    {
        if(v[i]>v[i+1])
        {
            cout<<"Not a BST"<<endl;
            return 0;
        }
    }
    cout<<"It is a BST"<<endl;
    return 0;
}