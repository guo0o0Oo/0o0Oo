#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,l;
struct qj{
    ll l,r;
}q[200010];
bool cmp(const qj a,const qj b){
    return a.l<b.l;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>l;
    ll x,r;
    for(ll i=1;i<=n;i++){
        cin>>x>>r;
        q[i].l=max((ll)0,x-r);
        q[i].r=min((ll)l,x+r);
    }
    sort(q+1,q+n+1,cmp);
    ll t=0;
    for(int i=1;i<=n;i++){
        if(q[i].l>t){
            cout<<"No\n";
            return 0;
        }
        t=max(t,q[i].r);
    }
    if(t==l){
        cout<<"Yes\n";
    }
    else cout<<"No\n";
    return 0;
}