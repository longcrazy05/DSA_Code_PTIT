#include<bits/stdc++.h>
using namespace std;

int n, s, mt[105][105];
set<int> adj[105];
bool vs[105];

void file(){
	freopen("CT.INP", "r", stdin);
	freopen("CT.OUT", "w", stdout);
}

int d=10000;
vector<int> res;
void dfs(int u, vector<int> &k, int cnt){
	if(cnt > d) return;
	vs[u] = true;
	for(int v: adj[u]){
		if(v==s && k.size() == n){
			if(cnt+mt[u][v] < d){
				res=k; d= cnt+mt[u][v];
				res.push_back(s);
			}
		}
		if(!vs[v]){
			k.push_back(v);
			cnt+=mt[u][v];
			dfs(v, k, cnt);
			k.pop_back();
			cnt-=mt[u][v];
		}
	}
	vs[u] = false;
}
int main(){
	//file();
	cin>>n>>s;
	int x;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>x;
			mt[i][j]=x;
			if(x && x!=10000) adj[i].insert(j);
		}
	}
	vector<int> k;
	k.push_back(s);
	dfs(s, k, 0);
	if(d==10000){
		cout<<0;
		return 0;
	}
	cout<<d<<endl;
	for(int i: res) cout<<i<<" ";
}
