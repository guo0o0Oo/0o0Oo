#include<bits/stdc++.h>
using namespace std;
int ans=0;
inline void check(int k){
	int data=10;
	while(k){
		if(k%10>=data)return;
		data=k%10;
		k/=10;
	}
	++ans;
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=n;i<=m;i++){
		check(i);
	}
	cout<<ans<<endl;
}
