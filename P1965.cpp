#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,k,x;
ll qp(ll a,ll k){
    ll res=1;
    while(k){
        if(k&1)res*=a;
        a*=a;
        a%=n;
        res%=n;
        k=k>>1;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k>>x;
    ll res=((qp(10,k)*m)%n+x)%n;
    cout<<res<<"\n";
    return 0;
}