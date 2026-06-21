#include<bits/stdc++.h>
using namespace std;
long long maxn,minn,smaxn,a;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int ts;cin>>ts;
	while(ts--){
		int n;cin>>n;
		maxn=LONG_LONG_MIN;minn=LONG_LONG_MAX;smaxn=LONG_LONG_MIN;
		for(int i=1;i<=n;i++){
			cin>>a;
			if(minn>a)minn=a;
			if(maxn<a){
				smaxn=maxn;
				maxn=a;
			}
			if(a!=maxn&&smaxn<a)smaxn=a;
		}
		cout<<max(smaxn,maxn-minn)<<"\n";
	}
}
