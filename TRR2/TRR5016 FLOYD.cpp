#include<bits/stdc++.h>
using namespace std;

int n;
int mt[105][105], nxt[105][105];
bool vs[105];

void file(){
	freopen("DN.INP", "r", stdin);
	freopen("DN.OUT", "w", stdout);
}

int main(){
	file();
	cin>>n;
	int x;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>mt[i][j];
			if(i==j) mt[i][j]=10000;
			if(mt[i][j]!=10000) nxt[i][j]=j;
		}
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(mt[i][j] > mt[i][k]+mt[k][j]){
					mt[i][j] = mt[i][k]+mt[k][j];
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}
	int a, b, res=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(mt[i][j] > res && mt[i][j] != 10000){
				res = mt[i][j];
				a=i; b= j;
			}	
		}
	}
	if(res ==0) cout<<0;
	else{
		cout<<a<<" "<<b<<" "<<res<<endl;
		vector<int> k;
		int u=a;
		while(1){
			k.push_back(u);
			if(u==b) break;
			u=nxt[u][b];
		}
		for(int i: k) cout<<i<<" ";
	}
}
