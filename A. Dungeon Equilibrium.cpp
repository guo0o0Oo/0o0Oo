#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int ts;cin>>ts;
	while(ts--){
		memset(a,0,sizeof(a));
		int x,n,ans=0;cin>>n;
		for(int i=0;i<n;i++){
			cin>>x;
			if(a[x]==x)ans++;
			else ++a[x];
		}
		for(int i=1;i<=n;i++){
			if(a[i]!=i){
				ans+=a[i];
			}
		}
		cout<<ans<<"\n";
	}
} 
