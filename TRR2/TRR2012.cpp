#include<bits/stdc++.h>
using namespace std;

int t, n, pre[105];
set<int> adj[105];
bool vs[105];

void file(){
	freopen("TK.INP","r",stdin);
	freopen("TK.OUT","w",stdout);
}

int d=0;
vector<vector<int>> res;
vector<int> k;

void bfs(int u){
	queue<int> q;
	q.push(u);
	vs[u]=true;
	while(q.size()){
		int x=q.front(); q.pop();
		k.push_back(x);
		for(int y : adj[x]){
			if(!vs[y]){
				vs[y]=true;
				q.push(y);
			}
		}
	}
}
int main(){
	file();
	cin>>n;
	int x;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>x;
			if(x) adj[i].insert(j);
		}
	}
	for(int i=1; i<=n; i++){
		k.clear();
		if(!vs[i]){
			bfs(i);
			sort(k.begin(), k.end());
			res.push_back(k);
		}
	}
	cout<<res.size()<<endl;
	for(auto it: res){
		for(auto i: it) cout<<i<<" ";
		cout<<endl;
	}
}
