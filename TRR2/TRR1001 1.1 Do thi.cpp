#include<bits/stdc++.h>
using namespace std;

int n, u, mtk[105][105], deg[105];
vector<int> adj[105];
bool vs[105];
vector<pair<int,int>> dsc;
void readfile(){
	freopen("DT.INP", "r", stdin);
	freopen("DT.OUT", "w", stdout);
}

int main(){
	readfile();
	int t;
	cin>>t>>n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>mtk[i][j];
			if(mtk[i][j]){
				deg[i]++;
				if(i< j)	dsc.push_back({i, j});
			}
		}
	}
	if(t==1){
		for(int i=1; i<=n; i++) cout<<deg[i]<<" ";
	}
	if(t==2){
		cout<<n<<" ";
		cout<<dsc.size()<<'\n';
		for(auto x: dsc){
			cout<<x.first<<" "<<x.second<<'\n';
		}
	}
}