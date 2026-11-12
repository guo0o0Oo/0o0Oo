#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,ll>;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,k;
queue<pr> q;
ll qpow(ll x,ll k){
    ll a=x,res=1;
    while(k){
        if(k&1)res*=a;
        a*=a;
        k>>=1;
    }
    return res;
}
void bfs(ll k){
    q.push({0,qpow(2,n)-1});
    k--;
    while(k){
        pr t=q.front();q.pop();
        ll mid=(t.first+t.second)>>1;
        q.push({t.first,mid});q.push({mid+1,t.second});
        k--;
    }
}
void pprint(ll l,ll r);
void invpprint(ll l,ll r){
    if(r-l==1){
        cout<<r<<" "<<l<<" ";
        return;
    }
    ll mid=(l+r)>>1;
    pprint(mid+1,r);
    invpprint(l,mid);
}
void pprint(ll l,ll r){
    if(r-l==1){
        cout<<l<<" "<<r<<" ";
        return;
    }
    ll mid=(l+r)>>1;
    pprint(l,mid);
    invpprint(mid+1,r);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;	cin>>T;
    while(T--){
        cin>>n>>k;
        if(n==1||qpow(2,n-2)<k){
            cout<<"No\n";
            continue;
        }
        cout<<"Yes\n";
        while(!q.empty())q.pop();
        bfs(k);
        for(ll i=1;i<=k;i++){
            pr t=q.front();q.pop();
            cout<<t.second-t.first+1<<" ";
            pprint(t.first,t.second);
            cout<<"\n";
        }
    }
    return 0;
}