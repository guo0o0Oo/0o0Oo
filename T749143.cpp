#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=5e6+10;
ll n,a[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(i==1||i==n||a[i]<0){
            ans+=a[i];
        }
        else{
            ans+=2*a[i];
        }
    }
    cout<<ans<<"\n";
    return 0;
}