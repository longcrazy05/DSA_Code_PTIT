#include<bits/stdc++.h>
using namespace std;

struct node{
	int d;
	node *l, *r;
	node(int x){
		d=x;
		l = r= NULL;
	}	
};

bool check(node *r1, node *r2){
	if(!r1 || !r2) return true;
	if(r1->d != r2->d) return false;
	if(r1->l && !r2->l || !r1->l && r2->l) return false;
	if(r1->r && !r2->r || !r1->r && r2->r) return false;
	return check(r1->l, r2->l) && check(r1->r, r2->r);
}
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int x, y, f1, f2; char c;
		map<int, node*> a, b;
		for(int i=0; i<n; i++){
			cin>>x>>y>>c;
			if(i==1) f1=x;
			if(!a[x]) a[x]=new node(x);
			if(!a[y]) a[y]=new node(y);
			if(c=='L') a[x]->l = a[y];
			else a[x]->r=a[y];
		}
		int m; cin>>m;
		for(int i=0; i<m; i++){
			cin>>x>>y>>c;
			if(i==1) f2=x;
			if(!b[x]) b[x]=new node(x);
			if(!b[y]) b[y]=new node(y);
			if(c=='L') b[x]->l = b[y];
			else b[x]->r=b[y];
		}
		if(n != m) cout<<"DIFFERENT";
		else{
			if(check(a[f1], b[f2])) cout<<"EQUAL";
			else cout<<"DIFFERENT";
		}
		cout<<endl;
	}
}