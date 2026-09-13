#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll x,y,l,r,a,b,ans=0;
    cin>>x>>y>>l>>r>>a>>b;
    for(ll i=a;i<b;i++){
        if(l<=i&&i<r){
            ans+=x;
        }
        else ans+=y;
    }
    cout<<ans<<"\n";
    return 0;
}