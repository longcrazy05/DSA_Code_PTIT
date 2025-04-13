#include<bits/stdc++.h>
using namespace std;

int t, n, u, mtk[105][105];
set<int> adj[105];
bool vs[105];
vector<int> ec;

void readfile(){
	freopen("CT.INP","r",stdin);
	freopen("CT.OUT","w",stdout);
}

void dfs(int x){
	vs[x]=true;
	for(int v: adj[x]){
		if(!vs[v]) dfs(v);
	}
}

int check(){
	dfs(1);
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(adj[i].size() % 2) cnt++;
		if(!vs[i]) return 0;
	}
	if(cnt == 0) return 1;
	else if(cnt == 2) return 2;
	else return 0;
}

void euler(int x){
	while(adj[x].empty() == false){
		int y=*adj[x].begin();
		adj[x].erase(y);
		adj[y].erase(x);
		euler(y);
	}
	ec.push_back(x);
	
}
int main(){
	cin>>t>>n;
	if(t==2) cin>>u;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>mtk[i][j];
			if(mtk[i][j]) adj[i].insert(j);
		}
	}
	
	if(t==1)	cout<<check();
	if(t==2){
		euler(u);
		reverse(ec.begin(), ec.end());
		for(int v: ec) cout<<v<<" ";
	}
}
