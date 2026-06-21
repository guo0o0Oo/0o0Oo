#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
struct pear{
    ll a,b,k;
    bool operator<(const pear &x)const{
        return k<x.k;
    }
}p[2010],newp[2010];
priority_queue<pear> q;
bool cmp1(pear &x,pear &y){
    return x.a<y.a;
}
bool cmp2(pear &x,pear &y){
    return x.b>y.b;
}
ll n,c1,c2,c3,ans=inf;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>c1>>c2>>c3;
    for(ll i=1;i<=n;i++)cin>>p[i].a>>p[i].b,p[i].k=p[i].a*c1+p[i].b*c2;
    sort(p+1,p+n+1,cmp1);
    for(ll i=1;i<=n;i++){
        ll mina=p[i].a;
        for(ll j=i;j<=n;j++)newp[j]=p[j];
        sort(newp+i,newp+n+1,cmp2);
        while(!q.empty())q.pop();
        for(ll j=i;j<=n;j++){
            ll minb=newp[j].b;
            ll val=mina*c1+minb*c2+c3;
            q.push(newp[j]);
            while(!q.empty()&&q.top().k>val)q.pop();
            ans=max(ans,ll(q.size()));
        }
    }
    cout<<ans<<"\n";
    return 0;
}