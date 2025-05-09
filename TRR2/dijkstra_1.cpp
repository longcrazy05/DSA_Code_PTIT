#include <bits/stdc++.h>
using namespace std;

int n, m, s;
int c[1005][1005], d[1005];
bool vs[1005];

void dijkstra(int s){
    vs[s] = true;
    
    for(int step = 1; step < n; step++){
        int u = 0, minn = 1e9;
        for(int i = 1; i <= n; i++){
            if(!vs[i] && d[i] < minn){
                minn = d[i];
                u = i;
            }
        }
        if(u == 0) break;
        vs[u] = true;
        
        for(int i = 1; i <= n; i++){
            if(!vs[i] && d[i] > d[u] + c[u][i]){
                d[i] = d[u] + c[u][i];
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        cout << d[i] << " ";
    }
    cout << "\n";
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> m >> s;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) c[i][j] = 1e9;
            c[i][i] = 0;
        }
        int x, y, z;
        while(m--){
            cin >> x >> y >> z;
            c[x][y] = min(c[x][y], z); 
            c[y][x] = min(c[y][x], z);
        }
        memset(vs, false, sizeof(vs));
        for(int i=1; i<=n; i++) d[i]=c[s][i];
        dijkstra(s);
    }
}
