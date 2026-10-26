#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n;
vector<ll> a(100010),all,rk(100010);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;
    cin>>T;
    while(T--){
        all.clear();
        cin>>n;
        for(ll i=1;i<=n;i++){
            ll dat;cin>>dat;
            a[i]=dat;
            all.push_back(dat);
        }
        sort(all.begin(),all.end());
        all.erase(unique(all.begin(),all.end()),all.end());
        for(ll i=1;i<=n;i++)rk[i]=lower_bound(all.begin(),all.end(),a[i])-(all.begin())+1;
        for(ll i=1;i<=n;i++)cout<<rk[i]<<" ";
        cout<<"\n";
    }
    return 0;
}