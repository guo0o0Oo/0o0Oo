#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m,a[500010],t[500010*4],tag[500010*4];
ll ls(ll p){return p<<1;}
ll rs(ll p){return p>>1;}
void pushup(ll p){
    t[p]=max(t[ls(p)],t[rs(p)]);
}
void pushdown(ll p){
    tag[ls(p)]+=tag[p];
    tag[rs(p)]+=tag[p];
    tag[p]=0;
}
void build(ll p,ll pl,ll pr){
    
}
ll update(ll p,ll pl,ll pr,ll L,ll R){
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    return 0;
}