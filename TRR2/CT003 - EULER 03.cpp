#include<bits/stdc++.h>
using namespace std;

int t, n, u;
set<int> adj[105], dsk[105];
bool vs[105];
vector<int> ec;
int degc[105], degt[105], mtk[105][105];

void file(){
	freopen("CT.INP","r", stdin);
	freopen("CT.OUT","w", stdout);
}

void dfs(int x){
	vs[x]=true;
	for(int v: dsk[x]){
		if(!vs[v]) dfs(v);
	}
}

int kt(){
	dfs(1);
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(!vs[i]) return 0;
		int x=abs(degc[i]-degt[i]);
		if(x == 1) cnt++;
		if(x > 1) return 0;
	}
	if(cnt == 0) return 1;
	else if(cnt == 2) return 2;
	else return 0;
}

void euler(int v){
	stack<int> st;
	st.push(v);
	while(!st.empty()){
		int x=st.top();
		if(adj[x].size() > 0){
			int y= *adj[x].begin();
			st.push(y);
			adj[x].erase(y);
		}
		else{
			st.pop();
			ec.push_back(x);
		}
	}
}
int main(){
    //file();
	cin>>t>>n;
	if(t==2) cin>>u;
	int k, l;
	for(int i=1; i<=n; i++){
		cin>>k;
		for(int j=0; j<k; j++){
			cin>>l;
			mtk[i][l]=1;
		}
	}
	for(int i=1; i<=n; i++){
	    for(int j=1; j<=n; j++){
	        if(mtk[i][j]) {
	            degc[i]++;
	            degt[j]++;
	            
	            adj[i].insert(j);
	            
	            dsk[i].insert(j);
	            dsk[j].insert(i);
	        }
	    }
	}
	if(t==1)	cout<<kt();
	if(t==2){
		euler(u);
		reverse(ec.begin(), ec.end());
		for(int x: ec) cout<<x<<" ";
	}
}