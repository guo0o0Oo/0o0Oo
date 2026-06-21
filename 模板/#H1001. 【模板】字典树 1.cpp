#include<bits/stdc++.h>
using namespace std;
const int N = 4e6+10;
int t[N][26];
bool vis[N];
int ans = 0;
int cnt = 1;
void insert(string s){
	int now = 0;
	for(int i = 0;i < (int)s.length();i++){
		int ch = s[i] - 'a';
		if(t[now][ch] == 0)
			t[now][ch] = cnt++;
		now = t[now][ch];
		if(i == (int)s.length() - 1 && !vis[now]){vis[now] = true;	ans++;}
	}
}
int main(){
	int n;	cin>>n;
	string s;
	for(int i = 0;i < n;i++){
		cin>>s;
		insert(s);
	}
	cout<<ans<<"\n";
	return 0;
}

