#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll n,sum=1,ans=0;
    cin>>n;
    for(ll i=1;i<=7;i++){
        sum*=n-i+1;
        sum/=i;
        if(i>=5)ans+=sum;
    }
    cout<<ans<<"\n";
    return 0;
}