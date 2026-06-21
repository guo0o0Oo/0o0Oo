#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,a=0,k;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>k;
        a+=k;
    }    
    if(a%n==0){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
    return 0;
}