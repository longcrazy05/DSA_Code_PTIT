#include<bits/stdc++.h>
using namespace std;

struct node{
	int d;
	node *l, *r;
	node(int x){
		d = x;
		l = r = NULL;
	}	
};
unordered_map<int, node*> mp;

void duyet(node *root){
	stack<node*> q1;
	stack<node*> q2;
	q2.push(root);
	while(!q1.empty() || !q2.empty()){
		while(!q2.empty()){
			node* x=q2.top(); q2.pop();
			cout<<x->d<<" ";
			if(x->r) q1.push(x->r);
			if(x->l) q1.push(x->l);
		}
		while(!q1.empty()){
			node *x = q1.top(); q1.pop();
			cout<<x->d<<" ";
			if(x->l) q2.push(x->l);
			if(x->r) q2.push(x->r);
		}
	}
}
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int x, y; char z;
		int f;
		mp.clear();
		for(int i=0; i<n; i++){
			cin>>x>>y>>z;
			if(i==0) f=x;
			if(!mp[x]) mp[x] = new node(x);
			if(!mp[y]) mp[y] = new node(y);
			if(z=='L') mp[x]->l = mp[y];
			else mp[x]->r = mp[y];
		}
		duyet(mp[f]);
		cout<<endl;
	}
}