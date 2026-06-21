#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e5+10;
ll n,a[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    ll ans=0;
    while(1){
        ll k=0,flag=1;
        for(ll i=1;i<=n;i++){
            if(k==0&&a[i]){
                flag=0;
                k=a[i];
                ans+=k;
            }
            k=min(a[i],k);
            a[i]-=k;
        }
        if(flag)break;
    }
    cout<<ans<<"\n";
    return 0;
}