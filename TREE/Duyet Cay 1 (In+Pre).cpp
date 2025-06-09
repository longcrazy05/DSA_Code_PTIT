#include<bits/stdc++.h>
using namespace std;

int pre[10005], inId[10005];
struct node{
	int d;
	node *l, *r;
	node(int x){
		d = x;
		l = r = NULL;
	}	
};
node* build(int l, int r, int &i){
	if(l > r) return NULL;
	int val = pre[i++];
	int pos = inId[val];
	node *root = new node(val);
	root->l = build(l, pos-1, i);
	root->r = build(pos+1, r, i);
	return root;
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
		for(int i=0; i<n; i++){
			int x; cin>>x;
			inId[x] = i;
		}
		for(int i=0; i<n; i++) cin>>pre[i];
		int i = 0;
		node *root = build(0, n-1, i);
		postOd(root);
		cout<<endl;
	}
}