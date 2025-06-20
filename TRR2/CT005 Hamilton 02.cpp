#include<bits/stdc++.h>
using namespace std;

int m, n, s, mt[105][105];
set<int> adj[105];
bool vs[105];

void file(){
	freopen("CT.INP","r",stdin);
	freopen("CT.OUT","w", stdout);
}

vector<vector<int>> res;

void dfs(int u, vector<int> k){
	vs[u]=true;
	for(int v: adj[u]){
		if(v==s && k.size()==n){
			res.push_back(k);
		}
		if(!vs[v]){
			k.push_back(v);
			dfs(v, k);
			k.pop_back();
		}
	}
	vs[u]=false;
}
int main(){
	//file();
	cin>>n>>m>>s;
	int x, y;
	for(int i=0; i<m; i++){
		cin>>x>>y;
		mt[x][y]=mt[y][x]=1;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(mt[i][j]) adj[i].insert(j);
		}
	}
	vector<int> k;
	k.push_back(s);
	dfs(s, k);
	cout<<res.size()<<endl;
	if(res.size()){
		for(auto vt: res){
			for(auto i: vt) cout<<i<<" ";
			cout<<s<<endl;
		}
	}
}
