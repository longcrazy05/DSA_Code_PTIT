#include<bits/stdc++.h>
using namespace std;

int t, n, m, s;
vector<pair<int,int>> adj[105];
bool vs[105];

void file(){
	freopen("CK.INP", "r", stdin);
	freopen("CK.OUT", "w", stdout);
}
struct canh{
	int u, v, w;
};
vector<canh> e;

void prim(int u){
	vector<canh> mst;
	int d=0;
	vs[u] = true;
	while(mst.size() < n-1){
		int a, b, minw=10000;
		for(int i=1; i<=n; i++){
			if(vs[i]){
				for(auto it: adj[i]){
					int v=it.first, w=it.second;
					if(!vs[v] && w < minw){
						a=i; b=v; minw=w;
					}
				}
			}
		}
		vs[b] = true;
		d+=minw;
		mst.push_back({min(a, b), max(a, b), minw});
	}
	cout<<d<<endl;
	for(auto e: mst){
		cout<<e.u<<" "<<e.v<<" "<<e.w<<endl;
	}
}
int main(){
	file();
	cin>>n>>s;
	int x;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>x;
			if(!x || x==10000) continue;
			adj[i].push_back({j, x});
		}
	}
	prim(s);
}
