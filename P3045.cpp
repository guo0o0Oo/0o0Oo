#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,ll>;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,k,m,p[50010],c[50010],ans;
bool cho[50010];
priority_queue<pr,vector<pr>,greater<pr> > cheap,origin,gap;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k>>m;
    for(ll i=1;i<=n;i++)cin>>p[i]>>c[i];
    for(ll i=1;i<=n;i++){
        cheap.push({c[i],i});
        origin.push({p[i],i});
    }
    for(ll i=1;i<=k;i++){
        ll pos=cheap.top().second;
        if(m<c[pos]){
            cout<<ans<<"\n";
            return 0;
        }
        gap.push({p[pos]-c[pos],pos});
        cho[pos]=1;
        m-=c[pos];
        ans++;
        cheap.pop();
    }
    for(ll i=k+1;i<=n;i++){
        while(cho[origin.top().second])origin.pop();
        while(cho[cheap.top().second])cheap.pop();
        ll oricost=origin.top().first,checost=cheap.top().first+gap.top().first;
        ll oripos=origin.top().second,chepos=cheap.top().second,repos=gap.top().second;
        if(oricost<checost){
            if(m<oricost)break;
            cho[oripos]=1;
            m-=oricost;
            ans++;
        }
        else{
            if(m<checost)break;
            cho[chepos]=1;
            gap.pop();
            gap.push({p[chepos]-c[chepos],chepos});
            m-=checost;
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}