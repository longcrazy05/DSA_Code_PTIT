#include<bits/stdc++.h>
using namespace std;

vector<int> s;

struct node{
	int d;
	node *l, *r;
	node(int x){
		d=x;
		l=r=NULL;
	}
};

int d;
void cnt(node *root){
	if(root->l){
		d++; cnt(root->l);
	}
	if(root->r){
		d++; cnt(root->r);
	}
}

node *build(int l, int d, int r){
	if(l > d || d > r) return NULL;
	int m1=(l+d)/2;
	int m2=(d+1+r)/2;
	node *root = new node(s[d]);
	root->l = build(l, m1, d-1);
	root->r = build(d+1, m2, r);
	return root;
}
void in(node *root){
	if(!root) return;
	in(root->l);
	cout<<root->d<<" ";
	in(root->r);
}
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		set<int> a;
		map<int,node*> mp;
		int x, y, f; char z;
		for(int i=0; i<n; i++){
			cin>>x>>y>>z;
			a.insert(x); a.insert(y);
			if(i==0) f=x;
			if(!mp[x]) mp[x] = new node(x);
			if(!mp[y]) mp[y] =new node(y);
			
			if(z=='L') mp[x]->l = mp[y];
			else mp[x]->r = mp[y];
		}
		d=0;
		cnt(mp[f]);
		for(auto i:a) s.push_back(i);
		node *root = build(0, d, a.size()-1);
		in(root);
		cout<<endl;
		s.clear();
	}
}

