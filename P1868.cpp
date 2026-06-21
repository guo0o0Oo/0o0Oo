#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct range{
    ll l,r;
    ll w;
}a[150010];
ll n,dp[150010];
bool cmp(const range& x,const range& y){
    return x.r<y.r;
}
ll min_pos(ll pos){
    ll l=0,r=n;
    while(l<r){
        ll mid=(l+r+1)>>1;
        if(pos<=a[mid].r)r=mid-1;
        else l=mid;
    }
    return l;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i].l>>a[i].r;
        a[i].w=a[i].r-a[i].l+1;
    }
    sort(a+1,a+n+1,cmp);
    for(ll i=1;i<=n;i++){
        ll pos=min_pos(a[i].l);
        dp[i]=max(dp[pos]+a[i].w,dp[i-1]);
    }
    cout<<dp[n];
    return 0;
}