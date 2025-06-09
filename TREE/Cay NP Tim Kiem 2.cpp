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

void build(node *r1, node *r2){
	if(r2->d < r1->d){
		if(!r1->l){
			r1->l = r2;
			return;
		}
		build(r1->l, r2);
	}
	if(r2->d > r1->d){
		if(!r1->r){
			r1->r = r2;
			return;
		}
		build(r1->r, r2);
	}
}

void postOd(node *root){
	if(!root) return;
	postOd(root->l);
	postOd(root->r);
	cout<<root->d<<" ";
}
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int f; cin>>f;
		node *r1= new node(f);
		int x; node *r2;
		for(int i=1; i<n; i++){
			cin>>x;
			r2 = new node(x);
			build(r1, r2);
		}
		postOd(r1);
		cout<<endl;
	}
}