#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e6+10;
ll n,m,d[N],s[N],t[N];
ll r[N],need[N];
void ask(ll pos){
    memset(need,0,sizeof(need));
    for(ll i=1;i<=pos;i++)need[s[i]]+=d[i],need[t[i]+1]-=d[i];
    for(ll i=1;i<=n;i++)need[i]+=need[i-1];
}
bool check(ll pos){
    ask(pos);
    for(ll i=1;i<=n;i++)if(need[i]>r[i])return 0;
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>r[i];
    for(ll i=1;i<=m;i++)cin>>d[i]>>s[i]>>t[i];
    ll l=1,r=n+1;
    while(l<r){
        ll mid=(l+r)>>1;
        if(check(mid))l=mid+1;
        else r=mid;
    }
    if(l==n+1){
        cout<<"0\n";
    }
    else{
        cout<<"-1\n";
        cout<<l<<"\n";
    }
    return 0;
}