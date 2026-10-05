#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,q,a[2000010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;	cin>>T;
    while(T--){
        cin>>n>>q;
        for(ll i=1;i<=n;i++)cin>>a[i];
        ll mn=inf,ans=inf;
        for(ll i=1;i<=n;i++)mn=min(mn,a[i]),ans=min(ans,i*mn);
        cout<<ans<<" ";
        for(ll i=1;i<=q;i++){
            ll x,y;cin>>x>>y;
            swap(a[x],a[y]);
            ans=min(a[x]*x,ans);
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
    return 0;
}