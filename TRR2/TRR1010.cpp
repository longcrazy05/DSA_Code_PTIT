#include<bits/stdc++.h>
using namespace std;

int t, n, deg[105], mtk[105][105], cnt;


void file(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w", stdout);
}
int main(){
    file();
	cin>>t>>n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>mtk[i][j]; 
			if(mtk[i][j]==10000) mtk[i][j]=0;
			if(mtk[i][j] && i < j) cnt++;
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(mtk[i][j]) deg[i]++;
			
		}
	}
	if(t==1){
		for(int i=1; i<=n; i++) cout<<deg[i]<<" ";
	}
	if(t==2){
		cout<<n<<" "<<cnt<<endl;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(mtk[i][j] && i < j) cout<<i<<" "<<j<<" "<<mtk[i][j]<<"\n";
			}
		}
	}
}