#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,m,a[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    ll l=0,r=ll(1e9);
    while(l<r){
        ll mid=(l+r+1)>>1;
        ll last=1,done=1;
        for(ll i=2;i<=n;i++){
            if(a[i]-a[last]>=mid){
                last=i;
                done++;
            }
        }
        if(done<m)r=mid-1;
        else l=mid;
    }
    cout<<l<<"\n";
    return 0;
}