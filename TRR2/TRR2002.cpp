#include<bits/stdc++.h>
using namespace std;

int t, n, u, v, pre[105];
set<int> adj[105];
bool vs[105];

void file(){
	freopen("TK.INP","r",stdin);
	freopen("TK.OUT","w",stdout);
}

int d=0;
vector<int> res;
bool ok=0;

void bfs(int s){
	queue<int> q;
	q.push(s);
	vs[s]=true;
	while(q.size()){
		int x=q.front(); q.pop();
		if(adj[x].find(v) != adj[x].end()){
			pre[v] = x; break;
		}
		for(int y : adj[x]){
			if(!vs[y]){
				q.push(y);
				vs[y]=true;
				pre[y]=x;
			}
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
			if(x) adj[i].insert(j);
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
		bfs(u);
		if(pre[v]){
			int k=v;
			while(k){
				res.push_back(k);
				k=pre[k];
			}
			reverse(res.begin(), res.end());
			for(auto i:res) cout<<i<<" ";
		}
		else cout<<0;
	}
}
