#include<bits/stdc++.h>
using namespace std;

struct node{
	int d;
	node *l ,*r;
	node(int x){
		d=x;
		l=r=NULL;
	}
};

bool solve(node *root, int d, int &lv){
	if(root->l && !root->r || root->r && !root->l) return false;
	if(!root) return true;
	if(!root->l && !root->r){
		if(lv == -1) lv = d;
		return lv == d;
	}
	return solve(root->l, d+1, lv) && solve(root->r, d+1, lv);
}
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		unordered_map<int, node*> mp;
		int x, y, f; char z;
		for(int i=0; i<n; i++){
			cin>>x>>y>>z;
			if(i==0) f=x;
			if(!mp[x]) mp[x]=new node(x);
			if(!mp[y]) mp[y]= new node(y);
			if(z=='L') mp[x]->l = mp[y];
			else mp[x]->r = mp[y];
		}
		int lv=-1;
		if(solve(mp[f], 0, lv)) cout<<"Yes";
		else cout<<"No";
		cout<<endl;
	}
}