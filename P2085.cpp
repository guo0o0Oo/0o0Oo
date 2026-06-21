#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,ll>;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,m,a[10010],b[10010],c[10010],x[100010];
priority_queue<pr,vector<pr>,greater<pr> > q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)x[i]=1;
    for(ll i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        q.push({a[i]+b[i]+c[i],i});
    }
    ll last;
    for(ll i=1;i<=m;i++){
        last=q.top().first;
        cout<<last<<" ";
        ll pos=q.top().second;
        q.pop();
        x[pos]++;
        q.push({a[pos]*x[pos]*x[pos]+b[pos]*x[pos]+c[pos],pos});
    }
    return 0;
}