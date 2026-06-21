#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=998244353;
struct Node{
    ll len,num;
    ll l,r; 
}G[5010];
ll qp(ll a,ll k){
    ll res=1;
    while(k){
        if(k&1)res=(res*a)%MOD;
        a=(a*a)%MOD;
        k>>=1;
    }
    return res;
}
ll re(ll k){
    return qp(k,MOD-2);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<(8*re(3))%MOD<<"\n";
    cout<<(117*re(20))%MOD<<"\n";
    return 0;
}