#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int,int>> adj[1005];
bool vs[1005];

struct canh{
	int x, y, w;
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
		cout<<min(e.x, e.y)<<" "<<max(e.x, e.y)<<" "<<e.w<<endl;
	}
}
void nhap(){
	cin>>n>>m;
	int x, y, w;
	while(m--){
		cin>>x>>y>>w;
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}
}
int main(){
	nhap();
	prim(5);
}
