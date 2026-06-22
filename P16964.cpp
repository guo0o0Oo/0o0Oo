#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,a[500010];
bool ifc(ll a,ll b){
    ll k=0;
    while(a||b){
        k+=(a&1)^(b&1);
        a>>=1;b>>=1;
    }
    return !(k&1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;	cin>>t;
    while(t--){
        cin>>n;
        for(ll i=1;i<=n;i++)cin>>a[i];
        ll cnt1=0,cnt2=0;
        cnt1+=a[1];
        for(ll i=2;i<=n;i++){
            if(ifc(a[i],a[1]))cnt1+=a[i];
            else cnt2+=a[i];
        }
        cout<<max(cnt1,cnt2)<<"\n";
    }
    return 0;
}