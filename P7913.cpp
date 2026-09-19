#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,ll>;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m1,m2,a1[100010],b1[100010],a2[100010],b2[100010];
pr p1[100010],p2[100010];
ll cnt1[100010],cnt2[100010];
priority_queue<ll,vector<ll>,greater<ll> > aval1,aval2;
priority_queue<pr,vector<pr>,greater<pr> > used1,used2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m1>>m2;
    for(ll i=1;i<=m1;i++)cin>>p1[i].first>>p1[i].second;
    for(ll i=1;i<=m2;i++)cin>>p2[i].first>>p2[i].second;
    sort(p1+1,p1+m1+1);
    sort(p2+1,p2+m2+1);
    for(ll i=1;i<=m1;i++)a1[i]=p1[i].first,b1[i]=p1[i].second;
    for(ll i=1;i<=m2;i++)a2[i]=p2[i].first,b2[i]=p2[i].second;
    for(ll i=1;i<=max(n,m1);i++)aval1.push(i);
    for(ll i=1;i<=max(n,m2);i++)aval2.push(i);
    for(ll i=1;i<=m1;i++){
        while(!used1.empty()&&used1.top().first<=a1[i]){
            aval1.push(used1.top().second);
            used1.pop();
        }
        cnt1[aval1.top()]++;
        used1.push({b1[i],aval1.top()});
        aval1.pop();
    }
    for(ll i=1;i<=m2;i++){
        while(!used2.empty()&&used2.top().first<=a2[i]){
            aval2.push(used2.top().second);
            used2.pop();
        }
        cnt2[aval2.top()]++;
        used2.push({b2[i],aval2.top()});
        aval2.pop();
    }
    for(ll i=1;i<=n;i++)cnt1[i]+=cnt1[i-1];
    for(ll i=1;i<=n;i++)cnt2[i]+=cnt2[i-1];
    ll mx=-inf;
    for(ll i=0;i<=n;i++){
        mx=max(mx,cnt1[i]+cnt2[n-i]);
    }
    cout<<mx;
    return 0;
}