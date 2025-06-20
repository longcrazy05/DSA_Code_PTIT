#include<bits/stdc++.h>
using namespace std;

int t, n, m, s, mtk[105][105];
vector<int> adj[105];
bool vs[105];

void file(){
	freopen("CK.INP", "r", stdin);
	freopen("CK.OUT", "w", stdout);
}

vector<pair<int,int>> res;
void dfs(int u){
	vs[u] = true;
	if(res.size()==n-1) return;
	for(int v: adj[u]){
		if(!vs[v]){
			res.push_back({min(u, v), max(u, v)});
			dfs(v);
		}
	}
	
}

void bfs(int u){
	queue<int> q;
	q.push(u);
	vs[u]=true;
	while(q.size()){
		if(res.size()==n-1) break;
		int x=q.front(); q.pop();
		for(int y: adj[x]){
			if(!vs[y]){
				q.push(y);
				vs[y] = true;
				res.push_back({min(x, y), max(x, y)});
			}
		}
	}
}
int main(){
	file();
	cin>>t>>n>>s;
	int x;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>x;
			if(x) adj[i].push_back(j);
		}
	}
	if(t==1)	dfs(s);
	else if(t==2)	bfs(s);
	if(res.size() != n-1) cout<<0;
	else if(res.size() == n-1){
		cout<<n-1<<endl;
		for(auto i: res){
			cout<<i.first<<" "<<i.second<<endl;
		}
	}
}
