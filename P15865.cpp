#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll cnt[100000]={0,2,4,8,6};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t,x,n;
    cin>>t>>x;
    ll ans;
    for(ll i=1;i<=x;i++){
        cin>>n;
        ans=2;
        if(n%2==0){
            ans+=2;
        }
        if(n%3==0){
            ans+=6;
        }
        if(n%4==0){
            ans+=4;
        }
        cout<<ans<<endl;
    }
    return 0;
}