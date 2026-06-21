#include<bits/stdc++.h>
using namespace std;
long long a[100010],sum,add,n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int ts;cin>>ts;
	while(ts--){
		cin>>n;
		sum=0;add=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		for(int i=1;i<n;i++){
			add+=a[i];
			if(add*2>sum){
				cout<<1;
				continue;
			}
			if(i<=n-2&&a[i+1]<a[i]&&a[i]+a[i+1]>a[i+2]){
				cout<<((add+a[i+1])*2>sum);
				continue;
			}
			else{
				cout<<0;
			}
		}
		cout<<"\n";
	}
} 
