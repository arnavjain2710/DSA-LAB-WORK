// Question 1
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node  *left , *right;
    int value;
};

Node* NewNode(int val)
{
    Node* newNode = new Node();
    newNode->value = val;
    newNode-> right = newNode-> left = NULL;
    return newNode;
}

// Inorder using recurrsion
void printInorder(Node* node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->value << " ";
    printInorder(node->right);
}

// Preorder using recurrsion
void printPreorder(Node* node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->value << " ";
    printInorder(node->left);
    printInorder(node->right);
}

// Postorder using recurrsion
void printPostorder(Node* node)
{
    if (node == NULL)
    {
        return;
    }
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->value << " ";
}

// Inorder using iteration
void Inorder(Node* root)
{
    stack<Node*> s;
    Node* curr = root;
    while (curr != NULL || s.empty() == false) 
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->value << " ";
        curr = curr->right;
    }
}

// Postoder using iteration
void Postorder(Node *root)
{
    if(root == NULL) return;
	stack<Node*> s1,s2;
	s1.push(root);
	Node* curr;
	while(s1.empty()==false){
		curr = s1.top();
		s1.pop();
		s2.push(curr);
		if(curr->left != NULL){
			s1.push(curr->left);
		}
		if(curr->right != NULL){
			s1.push(curr->right);
		}
	}
	while(s2.empty()==false){
		Node* curr = s2.top();
		s2.pop();
		cout<<curr->value<<" ";
	}

}

// Preorder using iteration
void Preorder(Node *root)
{
    if(root == NULL) return;
	stack<Node*> s;
	s.push(root);
	while(s.empty() == false){
		Node* curr = s.top();
		s.pop();
		cout<<curr->value<<" ";
		if(curr->right != NULL) s.push(curr->right);
		if(curr->left != NULL) s.push(curr->left);
	}

}
int main()
{
    Node* root = NewNode(5);
    root->left = NewNode(3);
    root->right = NewNode(8);
    root->left->left = NewNode(1);
    root->left->right = NewNode(4);
    root->right->right= NewNode(9);
    cout<<"Inorder traversal using recurrsion"<<endl;
    printInorder(root);
    cout<<endl;
    cout<<"Postorder traversal using recurrsion"<<endl;
    printPostorder(root);
    cout<<endl;
    cout<<"Preorder traversal using recurrsion"<<endl;
    printPreorder(root);
    cout<<endl;
    cout<<"Inorder traversal using iteration"<<endl;
    Inorder(root);
    cout<<endl;
    cout<<"Postorder traversal using iteration"<<endl;
    Postorder(root);
    cout<<endl;
    cout<<"Preorder traversal using recurrsion"<<endl;
    Preorder(root);
    cout<<endl;
    return 0;
}