#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,ans=0,node=1;
vector<int> road[maxn];
bool ip[maxn]={};

void dfs(int k,int num){
	if(k>ans){
		ans=k;
		node=num;
	}
	for(auto i:road[num]){
		if(!ip[i]){
			ip[i]=1;
			dfs(k+1,i);
			ip[i]=0;
		}
	}
}

int main(){
	cin>>n;
	int a,b;
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		road[a].push_back(b);road[b].push_back(a);
	}
	ip[1]=1;
	dfs(0,1);
	ip[1]=0;
	ip[node]=1;
	dfs(0,node);
	ip[node]=0;
	cout<<ans<<endl;
} 
