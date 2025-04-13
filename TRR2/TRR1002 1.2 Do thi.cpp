#include<bits/stdc++.h>
using namespace std;

int deg[105];
vector<int> dsk[105];
int t, n;

void openfile(){
	freopen("DT.INP","r", stdin);
	freopen("DT.OUT", "w", stdout);
}
int main(){
	openfile();
	cin>>t>>n;
	int x;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>x;
			if(x){
				deg[i]++;
				dsk[i].push_back(j);
			}
		}
	}
	if(t==1) for(int i=1; i<=n; i++) cout<<deg[i]<<" ";
	if(t==2){
		cout<<n<<'\n';
		for(int i=1; i<=n; i++){
			cout<<dsk[i].size()<<" ";
			for(int v: dsk[i]) cout<<v<<" ";
			cout<<'\n';
		}
	}
}