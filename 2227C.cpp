#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll a[200010],b[200010],c[200010],d[200010],e[200010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;	cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(ll i=1;i<=n;i++)cin>>a[i];
        ll cntb=0,cntc=0,cntd=0,cnte=0;
        for(ll i=1;i<=n;i++){
            ll gd=__gcd(a[i],ll(6));
            if(gd==6){
                b[++cntb]=a[i];
            }
            else if(gd==2){
                c[++cntc]=a[i];
            }
            else if(gd==3){
                d[++cntd]=a[i];
            }
            else e[++cnte]=a[i];
        }
        for(ll i=1;i<=n;i++){
            if(cntb)a[i]=b[cntb--];
            else if(cntc)a[i]=c[cntc--];
            else if(cnte)a[i]=e[cnte--];
            else a[i]=d[cntd--];
        }
        for(ll i=1;i<=n;i++)cout<<a[i]<<" ";
        cout<<"\n";
    }
    return 0;
}