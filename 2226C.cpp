#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,a[1000010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;	cin>>T;
    while(T--){
        cin>>n;
        ll mx=inf;
        for(ll i=1;i<=n;i++){
            ll x;cin>>x;
            a[x]++;
            mx=max(mx,x);
        }
        ll ans=0,p=0;
        for(ll i=0;i<=n;i++){
            if(a[ans]){
                ans++;
                a[ans]--;
            }
            else{
                p=ans*2+1;
                while(p<=mx&&a[p]==0)p++;
                if(p<=mx){
                    a[p]--;
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}