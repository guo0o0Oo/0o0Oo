#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e5+10;
ll n,a[N],b[N],cho[15][15],if_c[15];
ll dfs(ll dep){
    ll res=0;
    for(ll i=0;i<=9;i++){
        if(!if_c[i]){
            ll k=0;
            k+=cho[dep][i];
            if_c[i]=1;
            k+=dfs(dep+1);
            if_c[i]=0;
            res=max(res,k);
        }
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;	cin>>t;
    while(t--){
        memset(cho,0,sizeof(cho));
        cin>>n;
        char ch;
        for(ll i=1;i<=n;i++)cin>>ch,a[i]=ch-'0';
        for(ll i=1;i<=n;i++)cin>>ch,b[i]=ch-'0';
        for(ll i=1;i<=n;i++)cho[a[i]][b[i]]++;
        cout<<dfs(0)<<"\n";
    }
    return 0;
}