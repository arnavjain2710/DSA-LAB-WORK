// Question 4
#include<bits/stdc++.h>
using namespace std;

int count1 =0;

struct Node
{
    int value;
    Node *left , *right;
    Node(int x){
		value = x;
		left = NULL;
		right = NULL;
	}
};

void count_leafs(Node* node)
{
    if (node == NULL)
    {
        return;
    }
    if(node->left == NULL && node->right==NULL)
    {
        count1++;
    }
    count_leafs(node->left);
    count_leafs(node->right);
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right= new Node(9);
    root->right->right->right= new Node(9);
    root->right->right->left= new Node(9);
    count_leafs(root);
    cout<<"The number of leafs are: "<<count1<<endl;
    return 0;
}