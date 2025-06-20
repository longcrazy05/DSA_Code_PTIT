#include<bits/stdc++.h>
using namespace std;

int t, n, u, v, degc[105], degt[105];
vector<int> adj[105];
bool vs[105];

void file(){
	freopen("TK.INP","r",stdin);
	freopen("TK.OUT","w",stdout);
}

int d=0;
vector<int> res;
bool ok=0;

void dfs2(int s){
	if(ok) return;
	vs[s]=true;
	if(s==v){
		ok=true; return;
	}
	for(int i:adj[s]){
		if(!vs[i]){
			res.push_back(i);
			dfs2(i);
			if(ok) return;
			res.pop_back();
		}
	}
}
int main(){
	file();
	cin>>t>>n>>u>>v;
	int x;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>x;
			if(x) adj[i].push_back(j);
		}
	}
	if(t==1){
		for(int x: adj[u]){
			for(int y: adj[x]){
				if(y==v) d++;
			}
		}
		cout<<d;
	}
	else{
		res.push_back(u);
		dfs2(u);
		if(!vs[v]) cout<<0;
		else{
			for(int i:res) cout<<i<<" ";
		}
	}
}
