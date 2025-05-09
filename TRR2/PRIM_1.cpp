#include<bits/stdc++.h>
using namespace std;

int n, m, s;
int vs[1005];
vector<pair<int,int>> adj[1005];
struct canh{
	int u, v, w;
};

void prim(int u){
	vector<canh> mst; // cay khung
	int d=0; // chieu dai
	vs[u] = true;
	while(mst.size() < n-1){
		int minw=1e9;
		int a, b;
		for(int i=1; i<=n; i++){
			if(vs[i]){
				for(auto it: adj[i]){
					int v=it.first, ts=it.second;
					if(!vs[v] && ts < minw){
						minw=ts;
						a=v;
						b=i;
					}
				}
			}
		}
		mst.push_back({a, b, minw});
		d+=minw;
		vs[a]=true;
	}
	cout<<d<<endl;
	for(auto e: mst){
		cout<<min(e.u, e.v)<<" "<<max(e.u, e.v)<<" "<<e.w<<endl;
	}
}
int main(){
	int t; cin>>t;
	while(t--){
		cin>>n>>m>>s;
		int x, y, w;
		while(m--){
			cin>>x>>y>>w;
			adj[x].push_back({y, w});
			adj[y].push_back({x, w});
		}
		prim(s);
		memset(vs, false, sizeof(vs));
		for(int i=1; i<=n; i++) adj[i].clear();
	}
}
