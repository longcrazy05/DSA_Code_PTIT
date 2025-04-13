#include<bits/stdc++.h>
using namespace std;

int t, n;
int degc[105], degt[105], mtk[105][105];
vector<int> adj[105];
bool vs[105];
vector<vector<int>> path;
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
				dsc.push_back({i, j});
			}
		}
	}
	if(t==1){
		for(int i=1; i<=n; i++){
			cout<<degt[i]<<" "<<degc[i]<<'\n';
		}
	}
	if(t==2){
		cout<<n<<" "<<dsc.size()<<"\n";
		for(int i=1; i<=n; i++){
			for(auto x:dsc){
				if(i == x.first) cout<<1<<" ";
				else if(i == x.second) cout<<-1<<" ";
				else cout<<0<<" ";
			}
			cout<<endl;
		}
	}
}
