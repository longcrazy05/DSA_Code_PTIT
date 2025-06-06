#include<bits/stdc++.h>
using namespace std;

int n, s, t;
int d[1005], pre[1005];

struct canh{
	int u, v, w;
};
vector<canh> e;
void file(){
	freopen("BN.INP","r", stdin);
	freopen("BN.OUT","w", stdout);
}

bool bmf(int s){
	for(int i=1; i<=n; i++) d[i]=10000;
	d[s] = 0;
	for(int i=1; i<=n-1; i++){
		for(auto it :e){
			int u=it.u, v=it.v, w=it.w;
			if(d[v] > d[u]+w){
				d[v] = d[u] + w;
				pre[v] = u;
			}
		}
	}
	for(auto it :e){
		int u=it.u, v=it.v, w=it.w;
			if(d[v] > d[u]+w) return false;
	}
	return true;
}
int main(){
	file();
	cin>>n>>s>>t;
	int w;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>w;
			if(!w || w==10000) continue;
			e.push_back({i, j, w});
		}
	}
	if(bmf(s)){
		if(d[t] != 10000){
			cout<<d[t]<<endl;
			vector<int> res;
			while(1){
				res.push_back(t);
				if(t==s) break;
				t=pre[t];
			}
			for(int i=res.size()-1; i>=0; i--) cout<<res[i]<<" ";
			cout<<endl;
		}
		else cout<<0<<endl;
	}
	else cout<<-1<<endl;
}
