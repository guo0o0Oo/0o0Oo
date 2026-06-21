#include<bits/stdc++.h>
using namespace std;
int k,r;
char a[10010];
int main(){
	cin>>k>>r;
	int n=k,l=0;
	while(n){
		int o=n%r;
		n/=r;
		if(o<0){
			o-=r;
			n--;
		}
		if(o>9){
			a[l]=o-10+'A';
		}
		else{
			a[l]=o+'0';
		}
		l++;
	}
	cout<<k<<"=";
	for(int i=l-1;i>=0;i--){
		cout<<a[i];
	}
	cout<<"(base"<<r<<")";
	return 0;
}
