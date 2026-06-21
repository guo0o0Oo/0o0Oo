#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e5+10;
ll n,a[N];
priority_queue<ll> pq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;	cin>>t;
    while(t--){
        cin>>n;
        char ch;
        for(ll i=1;i<=n;i++)cin>>ch,a[i]=ch-'0';
        for(ll i=1;i<=n;i++){
            pq.push(a[i]);
            if(pq.size()>i/2)pq.pop();
        }
        ll ans=0;
        for(ll i=1;i<=n;i++)ans+=a[i]*10;
        while(!pq.empty()){
            ans-=pq.top()*9;
            pq.pop();
        }
        cout<<ans<<"\n";
    }
    return 0;
}