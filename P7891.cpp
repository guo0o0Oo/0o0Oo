#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define lowbit(x) ((x)&-(x))
const int N=100010;
ll n,a[N],rk[N],rrk[N],tree[N],x,y;
void insert(ll k){
    while(k<=N){
        tree[k]++;
        k+=lowbit(k);
    }
}
void cut(ll k){
    while(k<=N){
        tree[k]--;
        k+=lowbit(k);
    }
}
ll ask(ll k){
    ll res=0;
    while(k){
        res+=tree[k];
        k-=lowbit(k);
    }
    return res;
}
ll to_l(ll k){
    ll l=1,r=k;
    while(l<r){
        ll mid=(l+r)>>1;
        if(ask(mid)<k)l=mid+1;
        else r=mid;
    }
    return l;
}
ll to_r(ll k){
    ll l=k,r=n;
    while(l<r){
        ll mid=(l+r)>>1;
        if(ask(mid)>k)r=mid;
        else l=mid+1;
    }
    return l;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1])rk[i]=rk[i-1]+1;
        else rk[i]=rk[i-1];
        insert(rk[i]);
        rrk[rk[i]]=a[i];
    }
    ll cnt=rk[n];
    bool flag=1;
    for(int i=1;i<=n;i++){
        if(flag){
            ll l=1,r=cnt;
            while(l<r){
                ll mid=(l+r+1)>>1;
                if(rrk[mid]>x)r=mid-1;
                else l=mid;
            }
            if(ask(l)==0){
                x+=rrk[to_r(l)];
                cut(to_r(l));
            }
            else{
                x+=rrk[to_l(l)];
                cut(to_l(l));
            }
        }
        else{
            ll l=1,r=cnt;
            while(l<r){
                ll mid=(l+r+1)>>1;
                if(rrk[mid]>y)r=mid-1;
                else l=mid;
            }
            if(ask(l)==0){
                y+=rrk[to_r(l)];
                cut(to_r(l));
            }
            else{
                y+=rrk[to_l(l)];
                cut(to_l(l));
            }
        }
    }
    cout<<x<<"\n"<<y;
    return 0;
}