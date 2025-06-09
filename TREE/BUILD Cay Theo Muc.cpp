#include<bits/stdc++.h>
using namespace std;

struct node{
	string d;
	node *l, *r;
	node(string x){
		d=x;
		l = r= NULL;
	}	
};

void build(node *root, vector<string> s){
	queue<node*> q;
	q.push(root);
	int i = 1;
	while(q.size() && i < s.size()){
		node *x = q.front(); q.pop();
		if(s[i] != "N"){
			x->l = new node(s[i]);
			q.push(x->l);
		}
		i++;
		if(i >= s.size()) break;
		
		if(s[i] != "N"){
			x->r = new node(s[i]);
			q.push(x->r);
		}
		i++;
	}
}
void RNL(node *root){
	if(!root) return;
	RNL(root->r);
	cout<<root->d<<" ";
	RNL(root->l);
}
int main(){
	int t; cin>>t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin, s);
		stringstream ss(s);
		string w;
		vector<string> vt;
		while(ss>>w) vt.push_back(w);
		node *root = new node(vt[0]);
		build(root, vt);
		RNL(root);
		cout<<endl;
	}
}