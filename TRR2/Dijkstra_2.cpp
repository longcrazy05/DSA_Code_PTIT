#include <bits/stdc++.h>
using namespace std;

int n, m, s;
int d[1005];
bool vs[1005];
vector<pair<int,int>> adj[1005];

void ktao(){
	for(int i=1; i<=n; i++){
		d[i]=1e9;
		vs[i] = false;
		adj[i].clear();
	}
}
void dijkstra(int s) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    d[s] = 0;
    pq.push({0, s});
    while(pq.size()){
    	int u = pq.top().second; pq.pop();
    	if(vs[u]) continue;
    	vs[u] = true;
    	for(auto it: adj[u]){
    		int v= it.first, w= it.second;
    		if(d[v] > d[u] + w){
    			d[v] = d[u] + w;
    			pq.push({d[v], v});
			}
		}
	}
}

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n >> m >> s;
        ktao();
        int x, y, w;
        while(m--) {
            cin >> x >> y >> w;
            adj[x].push_back({y, w});
            adj[y].push_back({x, w});
        }
        dijkstra(s);
        for(int i=1; i<=n; i++) cout<<d[i]<<" ";
        cout<<endl;
    }
}
