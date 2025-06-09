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
			r1->l = r2; return;
		}
		build(r1->l, r2);
	}
	if(r2->d > r1->d){
		if(!r1->r){
			r1->r=r2; return;
		}
		build(r1->r, r2);
	}
}

void preOd(node *root){
	if(root ==NULL) return;
	cout<<root->d<<" ";
	preOd(root->l);
	preOd(root->r);
	
}
int main(){
	int t; cin>>t;
	while(t--){
		int n;
		cin>>n;
		unordered_map<int, node*> mp;
		int f, x;
		cin>>f;
		mp[f]=new node(f);
		for(int i=1; i<n; i++){
			cin>>x;
			mp[x]=new node(x);
			build(mp[f], mp[x]);
		}
		preOd(mp[f]);
		cout<<endl;
	}
}