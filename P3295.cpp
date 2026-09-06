#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e5+10;
const ll MOD=1e9+7;
ll n,m,fa[N][20],lg[N];
ll find(ll x,ll k){
    if(x!=fa[x][k])fa[x][k]=find(fa[x][k],k);
    return fa[x][k];
}
void merge(ll x,ll y,ll k){
    ll fx=find(x,k),fy=find(y,k);
    fa[fx][k]=fy;
}
ll qpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}
void init(){
    for(ll i=2;i<N;i++)lg[i]=lg[i/2]+1;
    for(ll j=0;j<20;j++)
        for(ll i=1;i+(1<<j)-1<N;i++)
            fa[i][j]=i;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    init();
    cin>>n>>m;
    for(ll i=1,l1,r1,l2,r2;i<=m;i++){
        cin>>l1>>r1>>l2>>r2;
        ll k=lg[r1-l1+1];
        merge(l1,l2,k);
        merge(r1-(1<<k)+1,r2-(1<<k)+1,k);
    }
    for(ll k=19;k>=1;k--){
        for(ll i=1;i+(1<<k)-1<=n;i++){
            merge(i,find(i,k),k-1);merge(i+(1<<(k-1)),find(i,k)+(1<<(k-1)),k-1);
        }
    }
    ll sum=0;
    for(ll i=1;i<=n;i++){
        if(find(i,0)==i)sum++;
    }
    ll ans=9*qpow(10,sum-1)%MOD;
    cout<<ans<<"\n";
    return 0;
}