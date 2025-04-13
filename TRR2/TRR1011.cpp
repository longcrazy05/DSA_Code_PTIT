#include<bits/stdc++.h>
using namespace std;

int t, n, m, deg[105], mtk[105][105], cnt;


void file(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w", stdout);
}
int main(){
	cin>>t>>n>>m;
	int x, y, z;
	for(int i=1; i<=m; i++){
		cin>>x>>y>>z;
		deg[x]++;
		deg[y]++;
		mtk[x][y]=z;
		mtk[y][x]=z;
	}
	if(t==1){
		for(int i=1; i<=n; i++) cout<<deg[i]<<" ";
	}
	if(t==2){
		cout<<n<<endl;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i != j && mtk[i][j] ==0) cout<<10000<<" ";
				else cout<<mtk[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}
