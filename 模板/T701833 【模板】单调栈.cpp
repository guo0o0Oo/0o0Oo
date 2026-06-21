#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=3e6+10;
ll a[maxn],f[maxn];
stack<int> st;
int main(){
	ll n,x;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x=a[i];
		while(!st.empty()&&a[st.top()]<x){
			f[st.top()]=i;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()){
		f[st.top()]=0;
		st.pop();
	}
	for(int i=1;i<=n;i++){
		cout<<f[i]<<" ";
	}
} 
