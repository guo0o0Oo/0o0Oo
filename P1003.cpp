#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+5;
int n,a[MAXN],b[MAXN],g[MAXN],k[MAXN],x,y;
bool check(int i){
	if(x>=a[i]&&x<a[i]+g[i]&&y>=b[i]&&y<b[i]+k[i]){
		return 1;
	}
	return 0;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i]>>g[i]>>k[i];
	}
	cin>>x>>y;
	for(int i=n-1;i>=0;i--){
		if(check(i)){
			cout<<i+1<<endl;
			return 0;
		}
	}
	cout<<-1;
	return 0;
} 