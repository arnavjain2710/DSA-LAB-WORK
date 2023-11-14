#include<bits/stdc++.h>
using namespace std;
struct node{
	node* right;
	node* left;
	int data;
	node(int val){
		right=NULL;
		left=NULL;
		data=val;
	}
};
int maxsum(node* root,int &ans){
	if(root==NULL) return 0;
	if(!root->right && !root->left)return root->data;
	
	int x=maxsum(root->left,ans);
	int y=maxsum(root->right,ans);
	
	if(root->left && root->right){
		ans=max(ans,x+y+root->data);
		return max(x,y) + root->data;
	}
	return (!root->left)? y+root->data: x+root->data; 
}
void print(node* root){
	int temp=INT_MIN;
	int ans=maxsum(root,temp);
	if(root->left && root->right){
	cout<<temp<<endl;
	}
	else{
	cout<<max(ans,temp)<<endl;
	}
}
int main(){
    node *root = new node(-15);
    root->left = new node(5);
    root->right = new node(6);
    root->left->left = new node(-8);
    root->left->right = new node(1);
    root->left->left->left = new node(2);
    root->left->left->right = new node(6);
    root->right->left = new node(3);
    root->right->right = new node(9);
    root->right->right->right= new node(0);
    root->right->right->right->left= new node(4);
    root->right->right->right->right= new node(-1);
    root->right->right->right->right->left= new node(10);
	
    print(root);
    
return 0;
}
