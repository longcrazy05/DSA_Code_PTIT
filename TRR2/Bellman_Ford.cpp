#include<bits/stdc++.h>
using namespace std;

int n, m, s;
int d[1005], pre[1005];
struct canh{
	int u, v, w;
};
vector<canh> e;

void ktao(){
	for(int i=1; i<=n; i++) d[i] = 1e9;
	e.clear();
}

bool bmf(int s){
	pre[s] = d[s] = 0;
	for(int i=1; i<=n-1; i++){
		for(auto it: e){
			int u=it.u, v=it.v, w=it.w;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				pre[v] = u;
			}
		}	
	}
	for(auto it: e){
		int u=it.u, v=it.v, w=it.w;
		if(d[v] > d[u] + w) return false;
	}
	return true;	
}
int main(){
	int t; cin>>t;
	while(t--){
		cin>>n>>m>>s;
		ktao();
		int x, y, z;
		while(m--){
			cin>>x>>y>>z;
			e.push_back({x, y, z});
		}
		if(bmf(s))
			for(int i=1; i<=n; i++) cout<<d[i]<<"|"<<pre[i]<<" ";
		else cout<<"CT am";
		cout<<endl;
	}
}