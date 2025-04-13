#include<bits/stdc++.h>
using namespace std;

int n, m, mtk[105][105], deg[105];
vector<int> adj[105];
bool vs[105];
vector<pair<int,int>> dsc;
void readfile(){
	freopen("DT.INP", "r", stdin);
	freopen("DT.OUT", "w", stdout);
}

int main(){
	//readfile();
	int t;
	cin>>t>>n>>m;
	
	int x, y;
	for(int i=1; i<=m; i++){
		cin>>x>>y;
		deg[x]++;
		deg[y]++;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	if(t==1)	for(int i=1; i<=n; i++) cout<<deg[i]<<" ";
	if(t==2){
		cout<<n<<endl;
		for(int i=1; i<=n; i++){
			cout<<adj[i].size()<<" ";
			for(int x: adj[i]) cout<<x<<" ";
			cout<<endl;
		}
	}
}