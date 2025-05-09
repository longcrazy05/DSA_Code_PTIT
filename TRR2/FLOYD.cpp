#include<bits/stdc++.h>
using namespace std;
using ll =long long;

int n, m, u, v, c, q;
int d[105][105];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++) d[i][j]=1e9;
		d[i][i]=0;
	}
	while(m--){
		cin>>u>>v>>c;
		d[u][v]=d[v][u]=c;
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(d[i][j] > d[i][k]+d[k][j]){
					d[i][j] = d[i][k]+d[k][j];
				}
			}
		}
	}
	cin>>q;
	while(q--){
		cin>>u>>v;
		cout<<d[u][v]<<'\n';
	}
}