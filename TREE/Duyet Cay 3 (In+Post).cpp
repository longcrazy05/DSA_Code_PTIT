#include<bits/stdc++.h>
using namespace std;

int post[10005];
unordered_map<int,int> inId;

struct node{
	int d;
	node *l, *r;
	node(int x){
		d = x;
		l = r = NULL;
	}	
};

node* build(int l ,int r, int &i){
	if(l > r) return NULL;
	int val = post[i--];
	int pos = inId[val];
	node* root = new node(val);
	root->r = build(pos+1, r, i);
	root->l = build(l, pos-1, i);
	return root;
}

void preOd(node* root){
	if(root == NULL) return;
	cout<<root->d<<" ";
	preOd(root->l);
	preOd(root->r);
}
int main(){
	int t; cin>>t;
	while(t--){
		inId.clear();
		int n; cin>>n;
		for(int i=0; i<n; i++){
			int x; cin>>x;
			inId[x]=i;
		}
		for(int i=0; i<n; i++){
			cin>>post[i];
		}
		int postId=n-1;
		node *root = build(0, n-1, postId);
		preOd(root);
		cout<<endl;
	}
}