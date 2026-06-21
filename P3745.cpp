#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll A,B,C,n,m,t[100010],b[100010],cost[100010];
ll over[100010],les[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>A>>B>>C;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>t[i];
    for(ll i=1;i<=m;i++)cin>>b[i];
    for(ll i=1;i<=n;i++)cost[t[i]+1]++;
    for(ll i=1;i<=100000;i++)cost[i]+=cost[i-1];
    for(ll i=1;i<=100000;i++)cost[i]+=cost[i-1];
    for(ll i=1;i<=m;i++)over[b[i]-1]++;
    for(ll i=100000;i>=1;i--)over[i]+=over[i+1];
    for(ll i=100000;i>=1;i--)over[i]+=over[i+1];
    for(ll i=1;i<=m;i++)les[b[i]+1]++;
    for(ll i=1;i<=100000;i++)les[i]+=les[i-1];
    for(ll i=1;i<=100000;i++)les[i]+=les[i-1];
    ll ans=sup;
    for(ll i=1;i<=100000;i++){
        ll res=0;
        if(A<B){
            if(les[i]>over[i])res+=over[i]*A;
            else res+=les[i]*A+(over[i]-les[i])*B;
        }
        else res+=over[i]*B;
        res+=cost[i]*C;
        ans=min(res,ans);
    }
    cout<<ans<<"\n";
    return 0;
}