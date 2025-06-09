#include<bits/stdc++.h>
using namespace std;

struct node{
	int d;
	node *l, *r;
	node(int x){
		d=x;
		l=r=NULL;
	}	
};

void build(node *root, int x){
	if(x < root->d){
		if(!root->l){
			root->l = new node(x);
			return;
		}
		build(root->l, x);
	}
	if(x > root->d){
		if(!root->r){
			root->r = new node(x);
			return;
		}
		build(root->r, x);
	}
}

void duyet(node *root, int &d){
	if(!root) return ;
	if(root->l || root->r) d++;
	duyet(root->l, d);
	duyet(root->r, d);
}
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int x; cin>>x;
		node *root = new node(x);
		for(int i=1; i<n; i++){
			cin>>x;
			build(root, x);
		}
		int d=0;
		duyet(root, d);
		cout<<d<<endl;
	}
}