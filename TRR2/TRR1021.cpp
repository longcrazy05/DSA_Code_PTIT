#include<bits/stdc++.h>
using namespace std;

int t, n, degc[105], degt[105];
struct canh{
	int u, v, w;
};
vector<canh> e;

void file(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);
}
int main(){
	file();
	cin>>t>>n;
	int x;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>x;
			if(x && x!= 10000){
				e.push_back({i, j, x});
				degc[i]++;
				degt[j]++;
			}
		}
	}
	if(t==1){
		for(int i=1; i<=n; i++){
			cout<<degt[i]<<" "<<degc[i]<<endl;
		}
	}
	if(t==2){
		cout<<n<<" "<<e.size()<<endl;
		for(auto it: e){
			cout<<it.u<<" "<<it.v<<" "<<it.w<<endl;
		}
	}
}
