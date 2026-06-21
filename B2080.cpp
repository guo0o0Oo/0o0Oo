#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    double x,ans=0;
    ll n;
    cin>>x>>n;
    for(ll i=0;i<=n;i++){
        ans*=x;
        ans+=1.0;
    }
    printf("%.2f",ans);
    return 0;
}