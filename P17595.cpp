#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,p;
vector<ll> pos;
bool ifh(ll l,ll r,ll k){
    cout<<"? ";
    for(ll i=l;i<=r;i++)cout<<i<<" ";
    for(ll i:pos)if(i<l||i>r)cout<<i<<" ";
    cout<<endl;
    ll res;
    cin>>res;
    if((res&(1<<k))==0)return 1;
    else return 0;
}
void fd(ll k){
    ll l=0,r=(1<<n);
    while(l<r){
        ll mid=(l+r+1)>>1;
        if(ifh(mid,r,k))l=mid;
        else r=mid-1;
    }
    pos.push_back(l);
}
bool ifh0(ll l,ll r){
    cout<<"? ";
    for(ll i=l;i<=r;i++)cout<<i<<" ";
    cout<<endl;
    ll res;
    cin>>res;
    if(res!=0)return 1;
    else return 0;
}
void fd0(){
    ll l=0,r=(1<<n);
    while(l<r){
        ll mid=(l+r+1)>>1;
        if(ifh0(mid,r))l=mid;
        else r=mid-1;
    }
    pos.push_back(l);
}
int main(){
    ll T;	cin>>T;
    while(T--){
        pos.clear();
        cin>>n>>p;
        fd0();
        for(ll i=1;i<=n;i++)fd(i);
        cout<<"! "<<pos[n]<<endl;
    }
    return 0;
}