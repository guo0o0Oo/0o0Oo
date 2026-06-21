#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define lowbit(x) ((x)&-(x))
ll n,m,k,p;
ll maxl(ll x){
    ll res,cnt=0;
    while(x){
        cnt++;
        res=lowbit(x);
        x-=res;
    }
    if(cnt==1)return res;
    return (res<<1);
}
int main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>m>>k>>p;
        ll op=1,res=0;
        while(n!=0&&m!=0){
            ll maxk=maxl(max(n,m));
            ll cnt=((maxk-k)*(maxk-k-1)/2);
            res+=op*(cnt*(maxk-(maxk-n)-(maxk-m)));
            op*=-1;
            n=maxk-n;
            m=maxk-m;
            cout<<n<<" "<<m<<"\n";
        }
        cout<<res<<"\n";
    }
    return 0;
}
