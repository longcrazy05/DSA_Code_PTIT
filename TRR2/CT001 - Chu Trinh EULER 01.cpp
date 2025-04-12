#include<bits/stdc++.h>
using namespace std;

int t, n, m, u;
bool vs[105];
set<int> adj[105];
vector<int> ec2;

void dfs(int x){
	vs[x]=true;
	for(int v : adj[x]){
		if(!vs[v]) dfs(v);
	}
}

int check(){
	dfs(1);
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(!vs[i]) return 0;
		if(adj[i].size() % 2) cnt++;
	}
	if(cnt == 0) return 1;
	if(cnt == 2) return 2;
	return 0;
}

void findEuler(int x) {
	while(!adj[x].empty()) {
		int y = *adj[x].begin();
		adj[x].erase(y);
		adj[y].erase(x);
		findEuler(y);
	}
	ec2.push_back(x);
}
int main(){
	cin>>t;
	if(t==1)	cin>>n>>m;
	if(t==2)	cin>>n>>m>>u;
	
	int matrix[n+1][n+1] = {};
	int x, y;
	for(int i = 0; i < m; i++) {
		cin >> x >> y;
		matrix[x][y] = 1;
		matrix[y][x] = 1;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(matrix[i][j])	adj[i].insert(j);
		}
	}
	if(t==1) cout<<check();
	if(t==2){
		findEuler(u);
		reverse(ec2.begin(), ec2.end());
		for(int i: ec2) cout<<i<<" ";
	}
}