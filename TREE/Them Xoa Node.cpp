#include<bits/stdc++.h>
using namespace std;

struct node{
	int d;
	node *l, *r;
	node(int x){
		d=x;
		l = r= NULL;
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

node *find(node *root){
	while(root->l) root=root->l;
	return root;
}

node *xoa(node *root, int x){
	if(!root) return NULL;
	if(x < root->d) root->l = xoa(root->l, x);
	else if(x > root->d) root->r = xoa(root->r, x);
	else{
		if(!root->l){
			node *tmp=root->r;
			delete root;
			return tmp;
		}
		else if(!root->r){
			node *tmp=root->l;
			delete root;
			return tmp;
		}
		node *tmp=find(root->r);
		root->d = tmp->d;
		root->r = xoa(root->r, tmp->d);
	}
	return root;
}

void pre(node *root){
	if(!root) return;
	cout<<root->d<<" ";
	pre(root->l);
	pre(root->r);
}

void inod(node *root){
	if(!root) return;
	inod(root->l);
	cout<<root->d<<" ";
	inod(root->r);
}
void post(node *root){
	if(!root) return;
	post(root->l);
	post(root->r);
	cout<<root->d<<" ";
}
int main(){
	int x, y;
	cin>>x>>y;
	node *root = new node(y);
	while(cin>>x){
		if(x==1){
			cin>>y;
			build(root, y);
		}
		else if(x==2){
			cin>>y;
			root = xoa(root, y);
		}
		else if(x==3){
			pre(root);
			cout<<endl;
		}
		else if(x==4){
			inod(root);
			cout<<endl;
		}
		else {
			post(root);
			cout<<endl;
		}
	}
}