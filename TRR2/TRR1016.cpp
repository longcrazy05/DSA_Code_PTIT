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
	cin>>t>>n>>m;
	int x, y;
	for(int i=1; i<=m; i++){
		cin>>x>>y;
		degc[x]++;
		degt[y]++;
		dsk[x].push_back(y);
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
