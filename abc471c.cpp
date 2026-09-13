#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=3e5+10;
ll n,p[N];
stack<ll> p1;
queue<ll> p2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>p[i];
    sort(p+1,p+n+1);
    for(ll i=1;i<=n;i++){
        if(p[i]<0)p1.push(p[i]);
        else p2.push(p[i]);
    }
    ll x=0,ans=0;
    for(ll i=1;i<=n;i++){
        if(p1.empty()){
            ans+=p2.front()-x;
            x=p2.front();
            p2.pop();
            continue;
        }
        else if(p2.empty()){
            ans+=x-p1.top();
            x=p1.top();
            p1.pop();
            continue;
        }
        if(x-p1.top()<=p2.front()-x){
            ans+=x-p1.top();
            x=p1.top();
            p1.pop();
        }
        else{
            ans+=p2.front()-x;
            x=p2.front();
            p2.pop();
        }
    }
    cout<<ans<<"\n";
    return 0;
}