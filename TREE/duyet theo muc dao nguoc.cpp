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

void RLO(node *root){
	queue<node*> q;
	stack<int> st;
	q.push(root);
	while(q.size()){
		node *x=q.front(); q.pop();
		st.push(x->d);
		if(x->r) q.push(x->r);
		if(x->l) q.push(x->l);
	}
	while(st.size()){
		cout<<st.top()<<" ";
		st.pop();
	}
}
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int x, y, f; char z;
		map<int, node*> mp;
		for(int i=0; i<n; i++){
			cin>>x>>y>>z;
			if(i==0) f=x;
			if(!mp[x]) mp[x] = new node(x);
			if(!mp[y]) mp[y] =new node(y);
			
			if(z=='L') mp[x]->l = mp[y];
			else mp[x]->r = mp[y];
		}
		RLO(mp[f]);
		cout<<endl;
	}
}
