#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll N=1e5+10;
struct resi{
    ll p,x,v,nowp,id;
    const bool operator<(const resi& y)const {
        return v<y.v;
    }
};
ll n,s[N],a[N],nowp=0,ifc[N],ans=0;
priority_queue<resi> pq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>s[i];
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++){
        resi r={s[i],a[i],s[i]*2+a[i],0,i};
        pq.push(r);
    }
    for(ll i=1;i<=n;i++){
        while(pq.top().nowp!=nowp||ifc[pq.top().id]){
            resi r=pq.top();
            pq.pop();
            if(!ifc[r.id]){
                pq.push({r.p,r.x,max(0ll,(r.p-nowp)*2)+r.x,nowp,r.id});
            }
        }
        resi r=pq.top();
        pq.pop();
        ans+=r.v;
        ifc[r.id]=1;
        nowp=max(nowp,r.p);
        cout<<ans<<"\n";
    }
    return 0;
}