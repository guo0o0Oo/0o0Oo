#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+5;
long long n,g1[MAXN],g2[MAXN],t1[MAXN][2],t2[MAXN][2],s1[MAXN],s2[MAXN];
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		int ans=0,t=0;
		char a;
		memset(t1,0,sizeof(t1));
		memset(t2,0,sizeof(t2));
		for(int i=0;i<n;i++){
			cin>>a;
			s1[i]=a-'0';
		}
		for(int i=0;i<n;i++){
			cin>>a;
			s2[i]=a-'0';
		}
		for(int i=0;i<n;i++){
			cin>>a;
			if(a=='0'){
				g1[i]=t+1;
				t1[t+1][s1[i]]++;
				t+=2;
			}
			else{
				g1[i]=t;
				t1[t][s1[i]]++;
			}
		}
		t=0;
		for(int i=0;i<n;i++){
			cin>>a;
			if(a=='0'){
				g2[i]=t+1;
				t2[t+1][s2[i]]++;
				t+=2;
			}
			else{
				g2[i]=t;
				t2[t][s2[i]]++;
			}
		}
		for(int i=0;i<n;i++){
			if(t1[g1[i]][0]>0&&t2[g2[i]][0]>0){
				ans++;
				t1[g1[i]][0]--;t2[g2[i]][0]--;
			}
			else if(t1[g1[i]][1]>0&&t2[g2[i]][1]>0){
				ans++;
				t1[g1[i]][1]--;t2[g2[i]][1]--;
			}
		}
		cout<<ans<<endl;
	}
}
