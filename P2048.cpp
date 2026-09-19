#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,K,L,R,a[500010],sum[500010],lg2[500010],ans;
pair<ll,ll> st[500010][20];
struct cho{
    ll o,l,r;
    pair<ll,ll> mx;
    bool operator<(const cho& a)const{
        return mx<a.mx;
    }
};
pair<ll,ll> rmq(ll o,ll l,ll r){
    ll k=lg2[r-l+1];
    if(st[l][k].first>st[r-(1<<k)+1][k].first)return {st[l][k].first-sum[o-1],st[l][k].second};
    else return {st[r-(1<<k)+1][k].first-sum[o-1],st[r-(1<<k)+1][k].second};
}
priority_queue<cho> pq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(ll i=2;i<=500000;i++)lg2[i]=lg2[i/2]+1;
    cin>>n>>K>>L>>R;
    for(ll i=1;i<=n;i++)cin>>a[i],sum[i]=sum[i-1]+a[i],st[i][0].first=sum[i],st[i][0].second=i;
    for(ll k=1;k<=19;k++){
        for(ll i=1;i+(1<<k)-1<=n;i++){
            st[i][k]=max(st[i][k-1],st[i+(1<<(k-1))][k-1]);
        }
    }
    for(ll i=1;i<=n-L+1;i++){
        pq.push({i,i+L-1,min(n,i+R-1),rmq(i,i+L-1,min(n,i+R-1))});
    }
    for(ll i=1;i<=K;i++){
        cho now=pq.top();pq.pop();
        ans+=now.mx.first;
        if(now.l<=now.mx.second-1)pq.push({now.o,now.l,now.mx.second-1,rmq(now.o,now.l,now.mx.second-1)});
        if(now.mx.second+1<=now.r)pq.push({now.o,now.mx.second+1,now.r,rmq(now.o,now.mx.second+1,now.r)});
    }
    cout<<ans<<"\n";
    return 0;
}