#include<bits/stdc++.h>
using namespace std;

vector<string> s;
int cal(int i){
	if(s[i] =="+") return cal(2*i+1)+cal(2*i+2);
	else if(s[i]=="-") return cal(2*i+1)-cal(2*i+2);
	else if(s[i]=="*") return cal(2*i+1)*cal(2*i+2);
	else if(s[i]=="/") return cal(2*i+1)/cal(2*i+2);
	else return stoi(s[i]);
}
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		for(int i=0; i<n; i++){
			string x;
			cin>>x;
			s.push_back(x);
		}
		cout<<cal(0)<<endl;
		s.clear();
	}
}