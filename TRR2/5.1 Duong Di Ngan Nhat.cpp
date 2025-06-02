#include<bits/stdc++.h>
using namespace std;

int n, s, t;
int d[1005], pre[1005];
vector<pair<int,int>> adj[1005];
bool vs[1005];

void file(){
	freopen("DN.INP","r", stdin);
	freopen("DN.OUT","w", stdout);
}
void dijkstra(int s){
	for(int i=1; i<=n; i++) d[i]=10000;
	d[s] = 0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
	pq.push({0, s});
	while(pq.size()){
		int u=pq.top().second; pq.pop();
		if(vs[u]) continue;
		vs[u] = true;
		for(auto it: adj[u]){
			int v=it.first, w=it.second;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				pre[v] = u;
				pq.push({d[v], v});
			}
		}
	}
}
int main(){
	cin>>n>>s>>t;
	int w;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>w;
			if(!w || w==10000) continue;
			adj[i].push_back({j, w});
		}
	}
	dijkstra(s);
	if(d[t] != 10000){
		cout<<d[t]<<endl;
		vector<int> res;
		while(1){
			res.push_back(t);
			if(t == s) break;
			t=pre[t];
		}
		for(int i=res.size()-1; i>=0; i--) cout<<res[i]<<" ";
		cout<<endl;
	}
	else cout<<0<<endl;
}
