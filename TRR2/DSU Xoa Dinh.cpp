#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, m;
vector<int> adj[MAXN]; 
bool ex[MAXN];
int pre[MAXN];
vector<string> res;

int find(int x) {
    if(pre[x] == x) return x;
    return pre[x]=find(pre[x]);
}

int tplt;
void uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        pre[b] = a;
        tplt--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
	
	for(int i=1; i<=n; i++) pre[i]=i;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
	int xoa[n];
	for(int i=0; i<n; i++) cin>>xoa[i];
	tplt = 0;
	for(int i=n-1; i>=0; i--){
		int u = xoa[i];
		ex[u] = true;
		tplt++;
		
		for(int v: adj[u]){
			if(ex[v]) uni(u, v);
		}
		if(tplt == 1) res.push_back("YES");
		else res.push_back("NO");
	}
	reverse(res.begin(), res.end());
	for(auto i: res) cout<<i<<endl;	
}