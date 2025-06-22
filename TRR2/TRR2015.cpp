#include<bits/stdc++.h>
using namespace std;

int n;
set<int> adj[105], dsk[105], rev[105];
bool vs[105];

void file(){
	freopen("TK.INP","r", stdin);
	freopen("TK.OUT","w", stdout);
}

int d=0;
void dfs(int u, set<int> adj[]){
	vs[u] = true;
	d++;
	for(int v: adj[u]){
		if(!vs[v]) dfs(v, adj);
	}
}

int main(){
    file();
	cin>>n;
	int x;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>x;
			if(x){
				adj[i].insert(j);
				rev[j].insert(i);
				
				dsk[i].insert(j);
				dsk[j].insert(i);
			}
		}
	}
	dfs(1, adj);
	if(d==n){
		d=0; 
		memset(vs, false, sizeof vs);
		dfs(1, rev);
		if(d==n){
			cout<<1; return 0;
		}
	}
	d=0;
	memset(vs, false, sizeof vs);
	dfs(1, dsk);
	if(d==n){
		cout<<2; return 0;
	}
	cout<<0;
}
