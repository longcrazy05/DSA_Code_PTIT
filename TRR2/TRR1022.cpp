#include<bits/stdc++.h>
using namespace std;

int t, n, m, degc[105], degt[105];
int mt[105][105];

void file(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);
}
int main(){
	file();
	cin>>t>>n>>m;
	int u, v, w;
	for(int i=0; i<m; i++){
		cin>>u>>v>>w;
		degc[u]++;
		degt[v]++;
		mt[u][v]=w;
	}
	if(t==1){
		for(int i=1; i<=n; i++){
			cout<<degt[i]<<" "<<degc[i]<<endl;
		}
	}
	if(t==2){
		cout<<n<<endl;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i==j){
					cout<<0<<" "; continue;
				}
				if(!mt[i][j]) cout<<10000<<" ";
				else cout<<mt[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}
