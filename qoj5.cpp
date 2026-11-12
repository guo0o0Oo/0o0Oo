#include<bits/stdc++.h>
#include "inv.h"
using namespace std;
using ll=long long;
int MOD;
ll u,v;
void init(int p){
    MOD=p;
}
int inv(int x){
    ll a=x,b=MOD,u=1,v=0;
    while(b){
        ll t=a/b;
        a-=t*b;swap(a,b);
        u-=t*v;swap(u,v);
    }
    u%=MOD;
    if(u<0)u+=MOD;
    return u;
}