#include<bits/stdc++.h>
using namespace std;

int n, m, s;
int d[1005], cnt[1005];
vector<pair<int,int>> adj[1005];
bool vs[1005];

void ktao(){
	for(int i=1; i<=n; i++){
		adj[i].clear();
		vs[i] = false;
		d[i] = 1e9;
		cnt = 0;
	}
}

void dijkstra(){
	d[1]=0; cnt[1]=1;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
	pq.push({0, 1});

	while(pq.size()){
		int u = pq.top().second; pq.pop();
		if(vs[u]) continue;
		vs[u] = true;
		for(auto it: adj[u]){
			int v = it.first, w=it.second;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				pq.push({d[v], v});
				cnt[v] = cnt[u];
			}
			else if(d[v] == d[u] + w) cnt[v]+=cnt[u];
		}
	}
}
int main(){
	int t; cin>>t;
	while(t--){
		cin>>n>>m;
		ktao();
		int x, y, z;
		for(int i=0; i<m; i++){
			cin>>x>>y>>z;
			adj[x].push_back({y, z});
			adj[y].push_back({x, z});
		}
		dijkstra();
		cout<<d[n]<<" "<<cnt[n];
		cout<<endl;
	}
}