#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e5+10;
ll n,q,h[N],st[N][20];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(ll i=1;i<=n;i++)cin>>h[i];
    for(ll i=1;i<=n;i++)st[i][0]=h[i],st[i][0]=h[i];
    for(ll i=1;i<20;i++){
        for(ll j=1;j+(1<<i)-1<=n;j++){
            st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
        }
    }
    while(q--){
        ll a,b;
        cin>>a>>b;
        ll l=__lg(b-a+1);
        cout<<max(st[a][l],st[b-(1<<l)+1][l])<<"\n";
    }
    return 0;
}