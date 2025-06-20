#include<bits/stdc++.h>
using namespace std;

int t, n, s, degc[105], degt[105];
set<int> adj[105];
bool vs[105];

void file(){
	freopen("CT.INP","r",stdin);
	freopen("CT.OUT","w", stdout);
}

void dfs(int u){
	vs[u]=true;
	for(int v:adj[u]){
		if(!vs[v]) dfs(v);
	}
}

int kt(){
	dfs(1);
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(!vs[i]) return 0;
		int x = abs(degc[i]-degt[i]);
		if(x==1) cnt++;
		if(x>1) return 0;
	}
	if(cnt==0) return 1;
	if(cnt==2) return 2;
	return 0;
}
vector<int> res;
void euler(int u){
	while(adj[u].size()){
		int v=*adj[u].begin();
		adj[u].erase(v);
		euler(v);
	}
	res.push_back(u);
}
int main(){
	file();
	cin>>t>>n;
	if(t==2) cin>>s;
	int x;
	for(int u=1; u<=n; u++){
		for(int v=1; v<=n; v++){
			cin>>x;
			if(x){
				adj[u].insert(v);
				if(t==1){
					adj[v].insert(u);
					degc[u]++;
					degt[v]++;
				}	
			}
		}
	}
	if(t==1) cout<<kt();
	else{
		euler(s);
		reverse(res.begin(), res.end());
		for(int i: res) cout<<i<<" ";
	}
}
