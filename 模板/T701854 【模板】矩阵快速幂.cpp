#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=101;
const int mod=1e9+7;
struct matrix{
	ll m[maxn][maxn];
};
ll n,k;
matrix operator*(const matrix &l,const matrix &r){
	matrix c;
	memset(c.m,0,sizeof(c.m));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				c.m[i][j]=(c.m[i][j]+l.m[i][k]*r.m[k][j])%mod;
			}
		}
	}
	return c;
}
matrix pow_matrix(matrix a,ll k){
	matrix ans;
	memset(ans.m,0,sizeof(ans.m));
	for(int i=1;i<=n;i++)ans.m[i][i]=1;
	while(k){
		if(k&1){
			ans=ans*a;
		}
		a=a*a;
		k=k>>1;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	matrix a;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a.m[i][j];
		}
	}
	matrix ans=pow_matrix(a,k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<ans.m[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
