#include<bits/stdc++.h>
using namespace std;
int n,a[100000];
bool ifc[100000];
int cnt;
void dfs(int dep){
    if(cnt==n)return ;
	if(dep==n){
        cnt++;
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<"\n";
	}
	for(int i=1;i<=n;i++){
		if(!ifc[i]&&i!=a[dep-1]+a[dep-2]){
			a[dep]=i;
			ifc[i]=1;
			dfs(dep+1);
			ifc[i]=0;
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
        cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				a[0]=i;a[1]=j;
				ifc[i]=1;ifc[j]=1;
				dfs(2);
				ifc[i]=0;ifc[j]=0;
			}
		}
	}
}