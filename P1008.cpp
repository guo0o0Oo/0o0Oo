#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll num[10],ifc[10];
inline ll unite(ll s1,ll s2,ll s3){return s1*100+s2*10+s3;}
inline void check(){
	ll a=unite(num[1],num[2],num[3]);
	ll b=unite(num[4],num[5],num[6]);
	ll c=unite(num[7],num[8],num[9]);
	if(c%a==0&&b%a==0&&c/a==3&&b/a==2){
		cout<<a<<" "<<b<<" "<<c<<endl;
		return;
	}
}
void dfs(ll size){
	if(size==10){
		check();
	}
	for(int i=1;i<=9;i++){
		if(!ifc[i]){
			ifc[i]=1;
			num[size]=i;
			dfs(size+1);
			ifc[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(ifc,0,sizeof(ifc));
	dfs(1);
}
