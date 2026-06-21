#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string,int> words;
	string s;
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(words[s]==1)continue;
		words[s]=1;cnt++;
	}
	cout<<cnt<<"\n";
	return 0;
}
