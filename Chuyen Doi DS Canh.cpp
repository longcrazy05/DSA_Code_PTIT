#include<bits/stdc++.h>
using namespace std;

int n,m;
int deg[1001], mtk[1001][1001], mtlt[1001][1001];
vector<int> dsk[1001];

void caldeg(int x, int y){
	deg[x]++;
	deg[y]++;	
}

void MTK(int x, int y){
	mtk[x][y]++;
	mtk[y][x]++;
}

void DSK(int x, int y){
	dsk[x].push_back(y);
	dsk[y].push_back(x);
}

void MTLT(int i, int x, int y){
	mtlt[x][i]=1;
	mtlt[y][i]=1;
}
int main(){
	cin>>n>>m;
	int x, y;
	for(int i=1; i<=m; i++){
		cin>>x>>y;
		caldeg(x, y);
		MTK(x,y);
		DSK(x,y);
		MTLT(i, x, y);
	}
	for(int i=1; i<=n; i++){
		cout<<"deg("<<i<<"): "<<deg[i]<<endl;
	}
	cout<<"\nMa tran ke:\n";
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++) cout<<mtk[i][j]<<" ";
		cout<<endl;
	}
	cout<<"\nDanh sach ke:\n";
	for(int i=1; i<=n; i++){
		cout<<"Ke "<<i<<": ";
		for(int x: dsk[i]) cout<<x<<" ";
		cout<<endl;
	}
	cout<<"\nMa tran lien thuoc:\n";
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++) cout<<mtlt[i][j]<<" ";
		cout<<endl;
	}
}
