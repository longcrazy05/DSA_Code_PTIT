#include <bits/stdc++.h>
using namespace std;

int deg[105];
int mtk[105][105];
int t, n, m;

void openfile() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
}

int main() {
    //openfile();
    cin >> t >> n >>m;

    int x,y;
    for(int i=1; i<=m; i++){
    	cin>>x>>y;
    	mtk[x][y]=1;
    	mtk[y][x]=1;
    	deg[x]++;
    	deg[y]++;
	}

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            cout << deg[i] << " ";
        }
    } else if (t == 2) {
        
        cout << n <<'\n';
        for (int i = 1; i <= n; i++) {
            for(int j=1; j<=n; j++) cout<<mtk[i][j]<<" ";
            cout << '\n';
        }
    }

    return 0;
}