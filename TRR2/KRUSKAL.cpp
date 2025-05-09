#include <bits/stdc++.h>
using namespace std;

int n, m;
int pre[1005], sz[1005];

struct canh{
	int x, y, w;
};
vector<canh> ds;
bool cmp(canh a, canh b){
	if(a.w == b.w) return a.x < b.x;
	return a.w < b.w;
}

void makeset(){
	for(int i=1; i<=n; i++){
		pre[i]=i;
		sz[i]=1;
	}
}

int find(int v){
	if(v == pre[v]) return v;
	return pre[v]= find(pre[v]);
}

bool uni(int a, int b){
	a=find(a);
	b=find(b);
	if(a==b) return false;
	if(sz[a] < sz[b]) swap(a, b);
	pre[b]=a;
	sz[a]+=sz[b];
	return true;
}

void kruskal(){
	vector<canh> mst;
	int d=0;
	
	for(int i=0; i<m; i++){
		if(mst.size() == n-1) break;
		canh e = ds[i];
		if(uni(e.x, e.y)){
			mst.push_back(e);
			d+=e.w;
		}
	}
	cout<<d<<endl;
	//for(auto e: mst){
		//cout<<min(e.x, e.y)<<" "<<max(e.x, e.y)<<" "<<e.w<<endl;
	//}
}
int main(){
	int t; cin>>t;
	while(t--){
		cin>>n>>m;
		int x, y, w;
		for(int i=0; i<m; i++){
			cin>>x>>y>>w;
			ds.push_back({x, y, w});
		}
		sort(ds.begin(), ds.end(), cmp);
		makeset();
		kruskal();
		
		ds.clear();
	}	
}
