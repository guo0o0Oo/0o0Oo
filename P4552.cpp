#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll N=1e5+10;
ll n,a[N],g[N],pcnt,ncnt;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++)g[i]=a[i]-a[i-1];
    for(ll i=2;i<=n;i++){
        if(g[i]>0)pcnt+=g[i];
        else ncnt-=g[i];
    }
    cout<<max(pcnt,ncnt)<<"\n";
    cout<<abs(pcnt-ncnt)+1<<"\n";
    return 0;
}