#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a,m;
ll extend_gcd(ll a,ll b,ll &x,ll &y){
    if(b==0){x=1;y=0;return a;}
    ll d=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
ll mod_inverse(ll a,ll m){
    ll x,y;
    extend_gcd(a,m,x,y);
    return (x%m+m)%m;
}
int main(){
    cin>>a>>m;
    a%=m;
    cout<<mod_inverse(a,m);
    return 0;
}