#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
struct Node{
	char l,r;
}t[400];
ll n,is_root[400],cnt;
char node[400];
void pre(char k){
    if(k=='*')return;
    cout<<k;
    pre(t[k-'a'].l);
    pre(t[k-'a'].r);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
    for(ll i=1;i<=n;i++){
        char a,b,c;
        cin>>a>>b>>c;
        t[a-'a'].l=b;t[a-'a'].r=c;
        is_root[b-'a']=1;is_root[c-'a']=1;
        node[cnt++]=a;
    }
    for(ll i=0;i<cnt;i++){
        if(!is_root[node[i]-'a'])pre(node[i]);
    }
	return 0;
}