#include<bits/stdc++.h>
using namespace std;
string s,s1;
int n,m,dp[2010][2010];
int dfs(int l1,int l2){
	if(dp[l1][l2]!=-1)return dp[l1][l2];
	if(s[l1-1]==s1[l2-1])return dfs(l1-1,l2-1);
	int res=INT_MAX;
	res=min(res,dfs(l1-1,l2)+1);
	res=min(res,dfs(l1,l2-1)+1);
	res=min(res,dfs(l1-1,l2-1)+1);
	return dp[l1][l2]=res;
}
int main(){
	cin>>s>>s1;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<2000;i++){
		dp[i][0]=i;
		dp[0][i]=i;
	}
	cout<<dfs(s.size(),s1.size());
	return 0;
}

