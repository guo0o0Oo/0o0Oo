#include<bits/stdc++.h>
using namespace std;
string number(int k){
	if(k==0){
		return "+[]";
	}
	string res="";
	for(int i=1;i<=k;i++){
		res+="+!+[]";
	}
	return res;
}
int main(){
	int a;
	cin>>a;
	string ans="";
	while(a){
		ans="+["+number(a%10)+"]"+ans;
		a/=10;
	}
	ans="+("+ans+")";
	cout<<ans<<endl;
}
