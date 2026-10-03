#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,cnt,ans=0;
pair<ll,ll> card[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>card[i].first>>card[i].second;
    }
    sort(card+1,card+n+1);
    cnt=unique(card+1,card+n+1)-(card+1);
    ll l1=1,r1=1;
    while(r1<=cnt){
        l1=r1;
        while(r1<=cnt&&card[r1].first==card[l1].first)r1++;
        ll last=l1;
        for(ll i=l1;i<r1;i++){
            while(card[i].second-card[last].second+1>n)last++;
            ans=max(ans,i-last+1);
        }
    }
    cout<<n-ans<<"\n";
    return 0;
}