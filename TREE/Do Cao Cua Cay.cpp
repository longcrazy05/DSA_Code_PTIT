#include<bits/stdc++.h>
using namespace std;

struct node{
	int d;
	node *pre;
	node(int x){
		d=x;
		pre=NULL;
	}	
};

void cnt(node* root, int &d){
	if(!root) return;
	if(root->pre) d++;
	cnt(root->pre, d);
}
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		map<int, node*> mp;
		int x, y;
		for(int i=0; i<n-1; i++){
			cin>>x>>y;
			if(!mp[x]) mp[x]=new node(y);
			mp[y] = new node(y);
			mp[y]->pre = mp[x];
		}
		int m=0;
		for(auto it: mp){
			int d=0;
			cnt(it.second, d);
			m=max(m, d);
		}
		cout<<m<<endl;
	}
}