#include<bits/stdc++.h>
using namespace std;
int a[13];
int main(){
	for(int i=1;i<=12;i++){
		cin>>a[i];
	} 
	int k=0,keep=0;
	for(int i=1;i<=12;i++){
		k+=300;
		if(k<a[i]){
			cout<<'-'<<i<<endl;
			return 0;
		}
		k-=a[i];
		keep+=k/100;
		k%=100;
	}
	cout<<k+keep*100+keep*20<<endl;
} 
