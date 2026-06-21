#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e5+10;
ll n,a[N],dp[100];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ll k=0,maxk=0,x=a[i];
        while(x){
            if(x&1)maxk=max(dp[k]+1,maxk);
            x>>=1;
            k++;
        }
        k=0;x=a[i];
        while(x){
            if(x&1)dp[k]=max(dp[k],maxk);
            ans=max(dp[k],ans);
            x>>=1;
            k++;
        }
    }
    cout<<ans;
    return 0;
}