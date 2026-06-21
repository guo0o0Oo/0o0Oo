#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll k[10000];
ll s;
void cut(ll &a,ll &b,ll y){
    a=a*y-b;
    b=b*y;
    if(a==0)return;
    ll data=__gcd(a,b);
    a/=data;
    b/=data;
}
void add(ll &a,ll &b,ll y){
    a=a*y+b;
    b=b*y;
    if(a==0)return;
    ll data=__gcd(a,b);
    a/=data;
    b/=data;
}
bool dfs(ll a,ll b,ll dep){
    if(a==0){
        for(int i=dep;i>=1;i--){
            cout<<k[i]<<" ";
        }
        return 1;
    }
    if(dep==s){
        return 0;
    }
    if(dep==s-1){
        if(a==1){
            if(k[dep-1]>b){
                k[dep]=b;
                return dfs(0,b,dep+1);
            }
            else return 0;
        }
        else return 0;
    }
    ll l=max((b+a-1)/a,k[dep-1]+1);
    ll r=min((s-dep+1)*b/a,(ll)1e7);
    for(int i=l;i<=r;i++){
        k[dep+1]=i;
        cut(a,b,i);
        if(dfs(a,b,dep+1))return 1;
        add(a,b,i);
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll a,b;
    cin>>a>>b;
    while(1){
        s++;
        if(dfs(a,b,0))break;
    }
    return 0;
}