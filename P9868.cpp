#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3005;
int n,m;
string max_s="",min_s[MAXN];
int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		sort(s.begin(),s.end());
		cout<<s<<endl;
		min_s[i]=s;
		reverse(s.begin(),s.end());
		cout<<s<<endl;
		if(s<max_s||max_s==""){
			max_s=s;
		}
	}
	for(int i=1;i<=n;i++){
		if(min_s[i]<max_s){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
} 
