#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,s=2,k=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		k++;
		if(k==s){
			k=1;
			s++;
		}
	}
	if(s%2==0){
		k=s-k;
	}
	cout<<k<<"/"<<s-k<<endl;
}
