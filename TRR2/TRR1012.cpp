#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long mod=1e9+7;

int mtk[105][105], n, t;
int degc[105], degt[105];
vector<pair<int,int>> dsc;


void file(){
	freopen("DT.INP","r", stdin);
	freopen("DT.OUT","w", stdout);
}
int main(){
	file();
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
			cout<<degt[i]<<" "<<degc[i]<<endl;
		}
	}
	if(t==2){
		cout<<n<<" "<<dsc.size()<<endl;
		for(auto x: dsc){
			cout<<x.first<<" "<<x.second<<endl;
		}
	}
}