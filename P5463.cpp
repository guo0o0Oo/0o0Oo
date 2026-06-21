#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x)&(-x))
using ll=long long;
const int N=1e6+10;
ll T[N],a[N];
pair<ll,ll> b[N];
void add(ll pos,ll d){
    while(pos<N){
        T[pos]+=d;
        pos+=lowbit(pos);
    }
}
ll ask(ll pos){
    ll res=0;
    while(pos){
        res+=T[pos];
        pos-=lowbit(pos);
    }
    return res;
}
int main(){
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i].first;
        b[i].second=i;
    }
    sort(b+1,b+n+1);
    b[0].first=-1;
    int rank=1;
    for(int i=1;i<=n;i++){
        if(b[i].first==b[i-1].first){
            a[b[i].second]=a[b[i-1].second];
            continue;
        }
        a[b[i].second]=rank++;
    }
    __int128 ans=0;
    for(int i=1;i<=n;i++){
        add(a[i],i);
        ans+=(ask(n)-ask(a[i]))*(n-i+1);
    }
    if(ans==0){
        cout<<0;
        return 0;
    }
    int cnt=0;
    int res[100];
    while(ans){
        res[cnt++]=ans%10;
        ans/=10;
    }
    for(int i=cnt-1;i>=0;i--){
        cout<<res[i];
    }
    return 0;
}