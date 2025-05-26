#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, q;
vector<pair<int,int>> e;
vector<pair<int,int>> cd;
bool del[200002];
int pre[200002], sz[200002];

void makeset(){
	for(int i=1; i<=n; i++){
		pre[i] = i;
		sz[i] = 1;
	}
}
int find(int x){
	if(pre[x] == x) return x;
	return pre[x] = find(pre[x]);
}

void uni(int a, int b){
	a=find(a); b=find(b);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	pre[b] = a;
	sz[a]+=sz[b];
}
int main(){
	cin>>n>>m>>q;
	int x, y;
	for(int i=0; i<m; i++){
		cin>>x>>y;
		e.push_back({x, y});
	}
	
	for(int i=0; i<q; i++){
		cin>>x>>y;
		x--;
		del[x] = true;
		cd.push_back({x, y});
	}
	
	makeset();
	for(int i=0; i<m; i++){
		x=e[i].first; 
		y=e[i].second;
		if(!del[i]) uni(x, y);
	}
	vector<int> res;
	for(int i=q-1; i>=0; i--){
		int stt = cd[i].first;
		int u = cd[i].second;
		res.push_back(sz[find(u)]);
		
		x=e[stt].first; y = e[stt].second;
		uni(x, y);	
	}
	reverse(res.begin(), res.end());
	for(auto i: res) cout<<i<<endl;
}
