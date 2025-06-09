#include<bits/stdc++.h>
using namespace std;

struct node{
	char data;
	node *left, *right;
	node(char x){
		data = x;
		left = right = NULL;
	}
};

void duyet(node *root){
	if(root == NULL) return;
	duyet(root->left);
	cout<<root->data;
	duyet(root->right);
	
} 
int main(){
	int t;
	cin>>t;
	while(t--){
		string s; cin>>s;
		stack<node*> st;
		for(char c: s){
			if(isalpha(c)){
				st.push(new node(c));
			}
			else{
				node *sign = new node(c);
				sign->right = st.top(); st.pop();
				sign->left = st.top(); st.pop();
				st.push(sign);
			}
		}
		duyet(st.top());
		cout<<endl;
	}
}