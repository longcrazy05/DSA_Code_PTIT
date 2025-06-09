#include<bits/stdc++.h>
using namespace std;

struct node {
	int d;
	node *l ,*r;
	node(int x){
		d=x;
		l=r=NULL;
	}	
};

bool solve(node* root){
	if(!root) return true;
	if(root->l && !root->r || !root->l && root->l) return false;
	return solve(root->l) && solve(root->r);
}
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		unordered_map<int,node*> mp;
		int x, y,f; char c;
		for(int i=0; i<n; i++){
			cin>>x>>y>>c;
			if(i==0) f=x;
			if(!mp[x]) mp[x] = new node(x);
			if(!mp[y]) mp[y] = new node(y);
			if(c=='L') mp[x]->l = mp[y];
			else mp[x]->r = mp[y];
		}
		cout<<solve(mp[f]);
		cout<<endl;
	}
}