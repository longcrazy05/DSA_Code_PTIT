#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
	Node(int x){
		data = x;
		left = right = NULL;
	}	
};

void insert(Node* &root, int x){
	if(root == NULL){
		root = new Node(x);
		return;
	}
	if(root->data > x) insert(root->left, x);
	if(root->data < x) insert(root->right, x);
}

void preOrder(Node *root){
	if(root == NULL) return;
	cout<<root->data<<" ";
	if(root->left) preOrder(root->left);
	if(root->right) preOrder(root->right);
	
}
int main(){
	int t, n, a[1005];
	cin>>t;
	while(t--){
		Node *root= NULL;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>a[i];
			insert(root, a[i]);
		}
		preOrder(root);
		cout<<endl;
	}
}