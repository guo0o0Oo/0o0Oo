#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,k,maxa=-1,mina=1000000010;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>k;
        if(k>maxa)maxa=k;
        if(k<mina)mina=k;
    }
    cout<<maxa-mina<<"\n";
    return 0;
}