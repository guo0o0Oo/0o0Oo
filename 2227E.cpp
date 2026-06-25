#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,a[200010],t[200010],mink[200010],sum[200010];
#define lowbit(x) ((x)&-(x))
void update(ll x,ll d){
    while(x<=n){
        t[x]=max(t[x],d);
        x+=lowbit(x);
    }
}
ll get(ll x){
    ll ans=0;
    while(x>0){
        ans=max(ans,t[x]);
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll s;	cin>>s;
    while(s--){
        cin>>n;
        for(ll i=1;i<=n;i++)t[i]=0;
        for(ll i=1;i<=n;i++)cin>>a[i];
        ll cnt=0,mina=sup,p=n;
        for(ll i=n;i>=1;i--){
            cnt+=max(0ll,a[i]-mina);
            mina=min(mina,a[i]);
            mink[i]=mina;
        }
        ll res=0;
        for(ll i=1;i<=n;i++){
            if(a[i]-1<mink[i]){
                res=max(res,i-get(a[i]-1)-1);
            }
            update(a[i],i);
        }
        cout<<max(cnt,cnt+res)<<"\n";
    } 
    return 0;
}