#include<bits/stdc++.h>
using namespace std;
__int128 dp[85][85],ans=0;
long long a[85][85],n,m;
__int128 f(int k,int l,int r){
	if(dp[l][r]!=-1)return dp[l][r];
	dp[l][r]=max(f(k,l+1,r)*2+a[k][l]*2,f(k,l,r-1)*2+a[k][r]*2);
	return dp[l][r];
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j]; 
		}
	}
	for(int i=1;i<=n;i++){
		memset(dp,-1,sizeof(dp));
		for(int j=1;j<=m;j++)dp[j][j]=a[i][j]*2;
		ans+=f(i,1,m);
	}
	if(ans==0){
		cout<<0;
		return 0;
	}
	stack<int> st;
	while(ans!=0){
		st.push(ans%10);
		ans/=10;
	}
	while(!st.empty()){
		cout<<st.top();
		st.pop();
	}
	return 0;
}
