#include<bits/stdc++.h>
using namespace std;

struct node{
	int d;
	node *l, *r;
	node(int x){
		d = x;
		l = r = NULL;
	}	
};

bool solve(node *root, int d, int &lv){
	if(root == NULL) return true;
	if(root->l == NULL && root->r == NULL){
		if(lv == -1) lv = d;
		return lv == d;
	}
	return solve(root->l, d+1, lv) && solve(root->r, d+1, lv);
}
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		unordered_map<int, node*> nodes;
        int f;

        for (int i = 0; i < n; ++i) {
            int x, y; char c;
            cin >> x >> y >> c;
            if (i == 0) f = x;

            if (!nodes[x]) nodes[x] = new node(x);
            if (!nodes[y]) nodes[y] = new node(y);

            if (c == 'L') nodes[x]->l = nodes[y];
            else nodes[x]->r = nodes[y];
        }
        int lv=-1;
        cout<<solve(nodes[f], 0, lv)<<endl;
	}
}