#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[200010],n,k;
int main(){
    ll t;cin>>t;
    while(t--){
        cin>>n>>k;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        if(k==0){
            cout<<a[1]<<"\n";
            continue;
        }
    }
}