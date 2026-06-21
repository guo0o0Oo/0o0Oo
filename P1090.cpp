#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
priority_queue<ll,vector<ll>,greater<ll> > q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,a;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a;
        q.push(a);
    }
    ll ans=0;
    for(ll i=1;i<n;i++){
        ll k=q.top();
        q.pop();
        k+=q.top();
        q.pop();
        ans+=k;
        q.push(k);
    }
    cout<<ans<<"\n";
    return 0;
}