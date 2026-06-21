#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main(){
	int n,s;
	cin>>n;
	s=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<n;i++){
		if(a[i-1]<=a[i]&&a[i]<=a[i+1]){
			s--;
			a[i]=a[i-1];
		}
	}
	cout<<s<<endl;
	return 0;
}
