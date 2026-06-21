#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n;
ll a[100010];
ll sum(ll l,ll r){
    ll res=0,pos=l,mina=1e6;
    for(ll i=l;i<=r;i++){
        mina=min(mina,a[i]);
    }
    for(ll i=l;i<=r;i++){
        a[i]-=mina;
    }
    res+=mina;
    for(ll i=l;i<=r;i++){
        if(a[i]==0){
            if(pos==i){
                pos++;
                continue;
            }
            res+=sum(pos,i-1);
            pos=i+1;
        }
    }
    if(pos!=r+1){
        res+=sum(pos,r);
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<sum(1,n);
    return 0;
}