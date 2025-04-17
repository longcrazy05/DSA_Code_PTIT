#include <bits/stdc++.h>
using namespace std;

int n, timer;
bool vs[105];
vector<int> dsk[105];
int low[105], in[105];
vector<pair<int, int>> br;

void file() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
}

void dfs(int u, int pre){
	vs[u] = true;
	low[u]=in[u]=timer++;
	
	for(int v: dsk[u]){
		if(v == pre) continue;
		if(!vs[v]){
			dfs(v, u);
			low[u]=min(low[u], low[v]);
			if(low[v] > in[u]) br.push_back({min(u,v), max(u,v)});
		}
		else low[u]=min(low[u], in[v]);
	}
}

int main() {
    file();
    cin >> n;
    int x;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> x;
            if (x)    dsk[i].push_back(j);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vs[i]) dfs(i, -1);
    }

    sort(br.begin(), br.end());
    cout << br.size() << "\n";
    for (auto x : br) {
        cout << x.first << " " << x.second << "\n";
    }
}