#include<bits/stdc++.h>
using namespace std;

int n, m;
int pre[1005], sz[1005];
struct canh{
	int u, v, w;
};
vector<canh> e;
bool cmp(canh a, canh b){
	if(a.w != b.w) return a.w < b.w;
	if(a.u != b.u ) return a.u < b.u;
	return a.v <b.v;
}

void file(){
	freopen("CK.INP","r", stdin);
	freopen("CK.OUT","w", stdout);
}

void makeset(){
	for(int i=1; i<=n; i++){
		pre[i]=i;
		sz[i] = 1;
	}
}

int find(int x){
	if(pre[x]==x) return x;
	return pre[x] = find(pre[x]);
}

bool uni(int a, int b){
	a=find(a); b=find(b);
	if(a==b) return false;
	if(sz[a] < sz[b]) swap(a, b);
	pre[b] = a;
	sz[a] += sz[b];
	return true;
}

void kruskal(){
	vector<canh> mst;
	int d=0;
	for(int i=0; i<m; i++){
		if(mst.size() == n-1) break;
		auto it = e[i];
		int u=it.u, v=it.v, w=it.w;
		if(uni(u, v)){
			mst.push_back({u, v, w});
			d+=w;
		}
	}
	if(mst.size()==n-1){
		cout<<d<<endl;
		for(auto i:mst){
			cout<<min(i.u, i.v)<<" "<<max(i.u, i.v)<<" "<<i.w<<endl;
		}
	}
	else cout<<0<<endl;
}

int main(){
	file();
	cin>>n>>m;
	int u, v, w;
	e.clear();
	for(int i=0; i<m; i++){
		cin>>u>>v>>w;
		e.push_back({u, v, w});
	}
	sort(e.begin(), e.end(), cmp);
	makeset();
	kruskal();
}
