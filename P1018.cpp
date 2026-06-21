#include<bits/stdc++.h>
using namespace std;
int n,k,a[50],mult[50]={},ans=0;
void check(){
	int num=0,res=1;
	for(int i=1;i<=n;i++){
		num*=10;
		num+=a[i];
		if(mult[i]){
			res*=num;
			num=0;
		}
	}
	ans=max(res,ans);
}
void dfs(int cnt,int pos){
	if(cnt==k){
		check();
		return ;
	}
	if(pos==n){
		return ;
	}
	dfs(cnt,pos+1);
	mult[pos]=1;
	dfs(cnt+1,pos+1);
	mult[pos]=0;
	return ;
}
int main(){
	cin>>n>>k;
	char ch;
	for(int i=1;i<=n;i++){
		cin>>ch;
		a[i]=ch-'0';
	}
	mult[n]=1;
	dfs(0,1);
	cout<<ans<<endl;
}
