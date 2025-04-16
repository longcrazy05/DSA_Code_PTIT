#include<bits/stdc++.h>
using namespace std;

int n, t;
int mtk[105][105], degc[105], degt[105];
vector<int> dsk[1001];
vector<pair<int,int>> dsc;


void file(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w", stdout);
}


int main(){
		
	cin>>t>>n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>mtk[i][j];
			if(mtk[i][j]){
				degc[i]++;
				degt[j]++;
				//dsc.push_back({i, j});
				dsk[i].push_back(j);
			}
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
			cout<<dsk[i].size()<<" ";
			for(int x: dsk[i]) cout<<x<<" ";
			cout<<endl;
		}
	}
}
