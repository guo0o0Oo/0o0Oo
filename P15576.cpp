#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x)&(-x))
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=2e5+10;
ll n,a[N],t1[N*2];
void update(ll k,ll d){
    while(k<=n){
        t1[k]+=d;
        k+=lowbit(k);
    }
}
ll ask(ll k){
    ll res=0;
    while(k){
        res+=t1[k];
        k-=lowbit(k);
    }
    return res;
}
void init(){
    for(ll i=-n+N;i<=n+N;i++){
        t1[i]=0;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;	cin>>T;
    while(T--){
        cin>>n;
        for(ll i=1;i<=n;i++)cin>>a[i];
        for(ll i=1;i<=n;i++)a[i+n]=a[i];
        init();
        ll f=0;
        for(ll i=1;i<=n;i++){
            update(a[i]-i+N,1);
            f+=abs(a[i]-i);
        }
        for(ll i=1;i<=n;i++){
            cout<<f<<"\n";
            
        }
        cout<<"\n";
    }
    return 0;
}