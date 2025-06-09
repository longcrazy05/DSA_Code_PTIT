#include<bits/stdc++.h>
using namespace std;

int pre[1005], inId[10005];

struct node{
	int d;
	node *l, *r;
	node(int x){
		d = x;
		l = r = NULL;
	}	
};

void duyet(node *root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* x=q.front(); q.pop();
		cout<<x->d<<" ";
		if(x->l) q.push(x->l);
		if(x->r) q.push(x->r);
	}
}

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int x, y; char c;
		
		node *s[10005];
		bool kt[10005];
		memset(kt, false, sizeof(kt));
		int f;
		for(int i=0; i<n; i++){
			cin>>x>>y>>c;
			if(i==0) f=x;
			if(!kt[x]) s[x] = new node(x);
			if(!kt[y]) s[y] = new node(y);
			if(c=='L') s[x]->l = s[y];
			else if(c=='R') s[x]->r = s[y];
			kt[x]=kt[y]=true;
		}
		duyet(s[f]);
		cout<<endl;
	}
}