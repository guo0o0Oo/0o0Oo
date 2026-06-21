#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e3+10;
int maxtime=INT_MIN,mintime=INT_MIN;
int main(){
	int l,n,b;
	cin>>l>>n;
	if(n==0){
		cout<<0<<" "<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>b;
		mintime=max(mintime,min(b,l-b+1));
		maxtime=max(maxtime,max(b,l-b+1));
	}
	cout<<mintime<<" "<<maxtime;
}
