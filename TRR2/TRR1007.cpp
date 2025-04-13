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
	cin>>t>>n;
	
	int k, x;
	for(int i=1; i<=n; i++){
		cin>>k;
		deg[i]=k;
		for(int j=0; j<k; j++){
			cin>>x;
			mtk[i][x]=1;
			mtk[x][i]=1;
			
		}
	}
	
	if(t==1)	for(int i=1; i<=n; i++) cout<<deg[i]<<" ";
	if(t==2){
		cout<<n<<endl;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++) cout<<mtk[i][j]<<" ";
			cout<<endl;
		}
	}
}