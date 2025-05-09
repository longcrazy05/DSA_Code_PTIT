#include <bits/stdc++.h>
using namespace std;

int n, m, s;
vector<pair<int, int>> adj[1005];
int d[1005];
bool vs[1005];

void dijkstra(int s) {
    for(int i = 1; i <= n; i++) d[i] = 1e9;
    d[s] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, s});
    
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if(vs[u]) continue;
        vs[u] = true;
        
        for(auto it : adj[u]) {
            int v = it.first, w = it.second;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << d[i] << " ";
    cout << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n >> m >> s;
        for(int i = 1; i <= n; i++) adj[i].clear();
        memset(vs, false, sizeof(vs));
        
        int x, y, w;
        while(m--) {
            cin >> x >> y >> w;
            adj[x].push_back({y, w});
            adj[y].push_back({x, w});
        }

        dijkstra(s);
    }
}
