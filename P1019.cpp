#include<bits/stdc++.h>
using namespace std;
string s[30];
int ans=0,n;
int ifc[30];
int check(int a,int b){
	for(int i=1;i<min(s[a].size(),s[b].size());i++){
		if(s[a].substr(s[a].size()-i,s[a].size())==s[b].substr(0,i)){
			return i;
		}
	}
	return 0;
}
void dfs(int k,int l){
	ans=max(ans,l);
	for(int i=1;i<=n;i++){
		if(ifc[i]!=2){
			int len=check(k,i);
			if(len!=0){
				ifc[i]++;
				dfs(i,l+s[i].size()-len);
				ifc[i]--;
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	cin>>s[n+1];
	for(int i=1;i<=n;i++){
		if(s[i][0]==s[n+1][0]){
			ifc[i]++;
			dfs(i,s[i].size());
			ifc[i]--;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
