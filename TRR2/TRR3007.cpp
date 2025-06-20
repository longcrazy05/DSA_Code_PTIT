#include<bits/stdc++.h>
using namespace std;

int n, m, s, mtk[105][105];
vector<int> adj[105];
bool vs[105];
vector<vector<int>> res;

void file(){
	freopen("CT.INP", "r", stdin);
	freopen("CT.OUT", "w", stdout);
}

void dfs(int u, vector<int> &k){
	vs[u]=true;
	for(int v: adj[u]){
		if(v==s && k.size()==n){
			res.push_back(k);
		}
		else if(!vs[v]){
			k.push_back(v);
			dfs(v, k);
			k.pop_back();
		}
	}
	vs[u] = false;
}
int main(){
	file();
	cin>>n>>s;
	int x;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>x;
			if(x) adj[i].push_back(j);
		}
	}
	vector<int> k;
	k.push_back(s);
	dfs(s, k);
	for(auto vt: res){
		for(auto i: vt) cout<<i<<" ";
		cout<<s<<endl;
	}
	cout<<res.size();
}
