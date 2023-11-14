// Question 3
#include<bits/stdc++.h>
using namespace std;

bool flag= true;
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

void compare_tree(Node* root , Node* root1)
{
    if(flag==false) return;
    if (root == NULL && root1 == NULL)
    {
        return;
    }
    else if(root ==NULL || root1 == NULL)
    {
        flag=false;
        return;
    }
    if(root->value != root1->value)
    {
        flag=false;
        return;
    }
    compare_tree(root->left , root1->left);
    compare_tree(root->right , root1->right);
}


int main()
{
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);

    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(8);
   

    compare_tree(root , root1);

    if(flag)
    {
        cout<<"Same trees"<<endl;
    }
    else
    {
        cout<<"Not same tree"<<endl;
    }
    return 0;
}