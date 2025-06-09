#include<bits/stdc++.h>
using namespace std;

int s[1005];
struct node{
	int d;
	node *l, *r;
	node(int x){
		d=x;
		l=r=NULL;
	}
};

node *build(int st, int e){
	if(st > e) return NULL;
	int mid = (st+e)/2;
	node *root = new node(s[mid]);
	root->l = build(st, mid-1);
	root->r = build(mid+1, e);
	return root;
}

void preOd(node *root){
	if(!root) return;
	cout<<root->d<<" ";
	preOd(root->l);
	preOd(root->r);
}
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		for(int i=0; i<n; i++)	cin>>s[i];
		sort(s, s+n);
		node *root = build(0, n-1);
		preOd(root);
		cout<<endl;
		for(int i=0 ;i<n; i++) s[i]=0;
	}
}