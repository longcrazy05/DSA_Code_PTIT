#include<bits/stdc++.h>
using namespace std;

int n, t, m;
int mtk[105][105], degc[105], degt[105];
vector<int> dsk[1001];
vector<pair<int,int>> dsc;


void file(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w", stdout);
}


int main(){
	file();	
	cin>>t>>n;
	int k;
	for(int i=1; i<=n; i++){
		cin>>k;
		int u;
		for(int j=0; j<k; j++){
			cin>>u;
			degc[i]++;
			degt[u]++;
			mtk[i][u]=1;
		}
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
				cout<<mtk[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}
