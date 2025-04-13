#include<bits/stdc++.h>
using namespace std;

int n, u, mtk[105][105];
vector<int> adj[105];
bool vs[105];
vector<vector<int>> path;

void readfile(){
	freopen("CT.INP", "r", stdin);
	freopen("CT.OUT", "w", stdout);
}
void solve(vector<int> s, int d, int x){
	for(int v: adj[x]){
		if(!vs[v]){
			vs[v]=true;
			s.push_back(v);
			if(d==n && v==u)	path.push_back(s);
			else	solve(s, d+1, v);
			vs[v]=false;
			s.pop_back();
		}
	}
}
int main(){
	//readfile();
	cin>>n>>u;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>mtk[i][j];
			if(mtk[i][j]) adj[i].push_back(j);
		}
	}
	vector<int> s;
	s.push_back(u);
	solve(s, 1, u);
	cout<<path.size()<<'\n';
	for(const auto &i: path){
		for(int j : i) cout<<j<<" ";
		cout<<'\n';
	}
	
}