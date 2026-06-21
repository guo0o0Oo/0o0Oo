#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a,b,c[200010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;	cin>>t;
    while(t--){
        memset(c,0,sizeof(c));
        ll n,k;
        cin>>n>>k;
        for(ll i=1;i<=k;i++){
            cin>>b>>a;
            c[b]+=a;
        }
        sort(c+1,c+k+1);
        ll ans=0;
        for(ll i=k;i>=k-n+1&&i>=1;i--){
            ans+=c[i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}