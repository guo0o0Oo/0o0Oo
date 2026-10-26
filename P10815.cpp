#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a,n;
inline ll read(){
    ll x=0,f=1;
    char ch=getchar_unlocked();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar_unlocked();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar_unlocked();}
    return x*f;
}
int main(){
    cout.tie(0);
    ll ans=0;
    n=read();
    for(ll i=1;i<=n;i++){
        a=read();
        ans+=a;
    }
    cout<<ans<<"\n";
}