#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m,k,x,y,a[200010],b[200010],needa[200010],needb[200010],trueneedb[200010];
void init(){
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    for(ll i=1;i<=n;i++)needa[i]=needa[i-1]+a[i];
    for(ll i=1;i<=m;i++)needb[i]=needb[i-1]+(b[i]%k==0?b[i]/k:b[i]/k+1);
    for(ll i=1;i<=m;i++)trueneedb[i]=trueneedb[i-1]+b[i];
}
ll cnt(ll num){
    if(needb[num]>y)return -inf;
    ll res=x+y*k-trueneedb[num];
    ll cnta=upper_bound(needa+1,needa+n+1,res)-needa-1;
    return cnta+num;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k>>x>>y;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=m;i++)cin>>b[i];
    init();
    ll mx=-inf;
    for(ll i=0;i<=m;i++){
        mx=max(mx,cnt(i));
        if(cnt(i)==-inf)break;
    }
    cout<<mx<<"\n";
    return 0;
}