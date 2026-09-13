#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,t,a,b,x,y,lastans,cnt,ans,l[1000010],fa[1000010],lg2[1000010];
int st[1000010][20];
pair<ll,ll> s[1000010],res[1000010];//first->sco,second->x
void init(){
    for(ll i=2;i<=1000000;i++)lg2[i]=lg2[i/2]+1;
}
ll find(ll x){
    if(fa[x]!=x)fa[x]=find(fa[x]);
    return fa[x];
}
void unite(ll x,ll y){
    ll fx=find(x),fy=find(y);
    if(fx!=fy){
        cnt--;
        ans+=l[fx]*l[fy]*2;
        l[fy]+=l[fx];
        fa[fx]=fy;
    }
}
pair<ll,ll> choose(pair<ll,ll> u,pair<ll,ll> v){
    if(u.first*v.second>v.first*u.second)return u;
    else if(u.first*v.second<v.first*u.second)return v;
    else if(u.second<v.second)return v;
    else return u;
}
ll ask(ll l,ll r){
    ll len=(r-l+1);
    if(choose(res[st[l][lg2[len]]],res[st[r-(1<<lg2[len])+1][lg2[len]]])==res[st[l][lg2[len]]])return st[l][lg2[len]];
    else return st[r-(1<<lg2[len])+1][lg2[len]];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    init();
    cin>>n>>t;
    for(ll i=1;i<=n;i++)cin>>s[i].first,s[i].second=i;
    sort(s+1,s+n+1);
    for(ll i=1;i<=n;i++){
        fa[s[i].second]=s[i].second;
        cnt++;
        l[s[i].second]=1;
        ans++;
        if(s[i].second>1&&fa[s[i].second-1])unite(s[i].second-1,s[i].second);
        if(s[i].second<n&&fa[s[i].second+1])unite(s[i].second,s[i].second+1);
        if(i<n&&s[i].first==s[i+1].first)continue;
        res[cnt]=choose(res[cnt],{ans,s[i].first});
    }
    for(ll i=1;i<=1000000;i++)st[i][0]=i;
    for(ll k=1;k<=20;k++){
        for(ll i=1;i+(1<<k)-1<=1000000;i++){
            if(choose(res[st[i][k-1]],res[st[i+(1<<(k-1))][k-1]])==res[st[i][k-1]])st[i][k]=st[i][k-1];
            else st[i][k]=st[i+(1<<(k-1))][k-1];
        }
    }
    while(t--){
        cin>>a>>b>>x>>y;
        ll l,r;
        l = (a * lastans % n + x - 1) % n + 1;
        r = (b * lastans % n + y - 1) % n + 1;
        if (l > r)swap(l, r);
        ll p=ask(l,r);
        if(res[p].first==0) cout<<-1<<" "<<-1<<"\n";
        else cout<<res[p].first<<" "<<res[p].second<<"\n";
        cout<<l<<" "<<r<<" "<<lastans<<"\n";
        if(res[p].first==0)lastans=1;
        else lastans=res[p].first*res[p].second%n;
    }
    return 0;
}