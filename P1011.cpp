#include<bits/stdc++.h>
using namespace std;
int a,b,n,m,x,f[30];
int main(){
	cin>>a>>n>>m>>x;
	f[1]=1;
	for(int i=2;i<21;i++)f[i]=f[i-1]+f[i-2];
	b=(m-f[n-3]*a-a)/(f[n-2]-1);
	cout<<f[x-2]*a+f[x-1]*b+a-b<<endl;
} 
