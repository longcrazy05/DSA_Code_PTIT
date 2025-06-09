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

void duyet(node *root, int d, int &m){
	if(!root) return;
	m = max(m, d);
	duyet(root->l, d+1, m);
	duyet(root->r, d+1, m);
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
		int m=0;
		duyet(root, 0, m);
		cout<<m<<endl;
	}
}