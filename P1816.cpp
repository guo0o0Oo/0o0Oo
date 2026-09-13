#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e5+10;
ll n,m,a[N],lg[N],st[N][20];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(ll i=2;i<N;i++)lg[i]=lg[i/2]+1;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++)st[i][0]=a[i];
    for(ll k=1;k<20;k++){
        for(ll i=1;i+(1<<k)-1<=n;i++){
            st[i][k]=min(st[i][k-1],st[i+(1<<(k-1))][k-1]);
        }
    }
    while(m--){
        ll l,r;
        cin>>l>>r;
        ll k=lg[r-l+1];
        cout<<min(st[l][k],st[r-(1<<k)+1][k])<<" ";
    }
    return 0;
}