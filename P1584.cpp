#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1010;
ll l[N][N],m[N][N],f[N][N]; 
int main(){
	ll n,low,h;
	cin>>n>>low>>h;
	for(int i=1;i<=n;i++)cin>>l[i][i];
	for(int i=1;i<=n;i++)cin>>m[i][i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			m[i][j]=m[i][j-1]+m[j][j];
			l[i][j]=l[i][j-1]+l[j][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(l[i][j]<low||h<l[i][j]){
				m[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			f[i][j]=max(f[i][j-1],f[i-1][j]);
			f[i][j]=max(f[i-1][j-1]+m[i][j],f[i][j]);
		}
	}
	cout<<f[n][n];
	return 0;
}
