#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=5e5+10;
ll n,q,a[N],b[N],op;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++){
        b[a[i]]=i;
    }
    for(ll i=1;i<=q;i++){
        ll x,y,z;
        cin>>x;
        if(x==1){
            cin>>y>>z;
            if(op){
                swap(b[y],b[z]);
                swap(a[b[y]],a[b[z]]);
            }
            else{
                swap(a[y],a[z]);
                swap(b[a[y]],b[a[z]]);
            }
        }
        else{
            op=1-op;
        }
    }
    if(op){
        for(ll i=1;i<=n;i++)cout<<b[i]<<" ";
    }
    else{
        for(ll i=1;i<=n;i++)cout<<a[i]<<" ";
    }
    return 0;
}