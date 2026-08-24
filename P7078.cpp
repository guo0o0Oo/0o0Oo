#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,ll>;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e6+10;
ll n,a[N],ans,eater[N],eatener[N];
deque<pr> q1,q2;
void solve(){
    memset(eater,0,sizeof(eater));
    memset(eatener,0,sizeof(eatener));
    while(!q1.empty())q1.pop_back();
    while(!q2.empty())q2.pop_back();
    for(ll i=1;i<=n;i++)q1.push_front({a[i],i});
    for(ll i=1;i<n;i++){
        pr x,y;
        if(q2.empty())x=q1.front(),q1.pop_front();
        else if(q1.empty())x=q2.front(),q2.pop_front();
        else{
            if(q1.front()>=q2.front())x=q1.front(),q1.pop_front();
            else x=q2.front(),q2.pop_front();
        }
        if(q2.empty())y=q1.back(),q1.pop_back();
        else if(q1.empty())y=q2.back(),q2.pop_back();
        else{
            if(q1.back()<=q2.back())y=q1.back(),q1.pop_back();
            else y=q2.back(),q2.pop_back();
        }
        eater[i]=x.second;
        eatener[i]=y.second;
        x.first-=y.first;
        if(x.first>=q1.back().first)q1.push(x);
        else q2.push(x);

    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;	cin>>T;
    T--;
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    solve();
    while(T--){
        ll k,x,y;
        cin>>k;
        for(ll i=1;i<=k;i++){
            cin>>x>>y;
            a[x]=y;
        }
        solve();
    }
    return 0;
}