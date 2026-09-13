#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll m,d,st[200010][20],lg[200010],t,len;
ll ask(ll l,ll r){
    if(l>r)return 0;
    ll k=lg[r-l+1];
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(ll i=2;i<=200000;i++)lg[i]=lg[i/2]+1;
    cin>>m>>d;
    while(m--){
        char op;
        ll x;
        cin>>op>>x;
        if(op=='A'){
            len++;
            ll now=(t+x)%d;
            for(ll k=0;(1<<k)<=len;k++){
                st[len-(1<<k)+1][k]=max(ask(len-(1<<k)+1,len-1),now);
            }
        }
        else{
            t=ask(len-x+1,len);
            cout<<t<<"\n";
        }
    }
    return 0;
}