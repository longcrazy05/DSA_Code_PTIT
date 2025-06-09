#include<bits/stdc++.h>
using namespace std;

vector<string> s;
int n;
struct node{
	string d;
	node *left, *right;
	node(string x){
		d = x;
		left = right = NULL;
	}	
};

node* build(int i){
	if(i >= n) return NULL;
	node* root= new node(s[i]);
	root->left = build(i*2+1);
	root->right = build(i*2+2);
	return root;
}

int cal(node *root){
	if(!root->left && !root->right) return stoi(root->d);
	string x = root->d;
	int l = cal(root->left);
	int r= cal(root->right);
	if(x == "+") return l + r;
	else if(x == "-") return l - r;
	else if(x == "*") return l * r;
	else if(x == "/") return l / r;
}
int main(){
	int t; cin>>t;
	while(t--){
		cin>>n;
		string x;
		for(int i=0; i<n; i++){
			cin>>x;
			s.push_back(x);
		}
		node *root = build(0);
		cout<<cal(root);
		cout<<'\n';
		s.clear();
	}
}