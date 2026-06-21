#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int ans=n;
	while(n>=k){
		int data=n/k;
		ans+=data;
		n%=k;
		n+=data;
	}
	cout<<ans<<"\n";
	return 0;
}

