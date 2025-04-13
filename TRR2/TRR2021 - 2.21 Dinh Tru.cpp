#include<bits/stdc++.h>
using namespace std;

int n, mtk[105][105];
bool vs[105];
vector<int> adj[105];

void file(){
	freopen("TK.INP","r", stdin);
	freopen("TK.OUT", "w", stdout);
}
void dfs(int u){
	vs[u]=true;
	for(int v: adj[u]){
		if(!vs[v]) dfs(v);
	}
}

void bfs(int u){
	queue<int> q;
	q.push(u);
	vs[u]=true;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int y : adj[x]){
			if(!vs[y]){
				q.push(y);
				vs[y]=true;
			}
		}
	}
}
int tplt(){
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(!vs[i]){
			//dfs(i);
			bfs(i);
			cnt++;
		}
	}
	return cnt;
}
int main(){
	//file();
	cin>>n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>mtk[i][j];
			if(mtk[i][j]) adj[i].push_back(j);
		}
	}
	int k=tplt();
	int x;
	vector<int> kq;
	for(int i=1; i<=n; i++){
		memset(vs, false, sizeof(vs));
		vs[i]=true;
		x=tplt();
		if(x>k) kq.push_back(i);
	}
	cout<<kq.size()<<"\n";
	for(int i: kq) cout<<i<<" ";
}