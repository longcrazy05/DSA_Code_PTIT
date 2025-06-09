#include<bits/stdc++.h>
using namespace std;

int n, a[10005];
void solve(int i){
	if(i >=n) return;
	solve(2*i+1);
	cout<<a[i]<<" ";
	solve(2*i+2);
}
int main(){
	int t; cin>>t;
	while(t--){
		cin>>n;
		for(int i=0; i<n; i++) cin>>a[i];
		solve(0);
		cout<<endl;
	}
}