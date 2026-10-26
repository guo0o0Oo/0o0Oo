#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
bitset<500010> s;
ll n,q,mult[500010],inmult[500010];
stack<ll> st;
ll pw(ll x,ll k){
    ll a=x,res=1;
    while(k){
        if(k&1)res=res*a%MOD;
        a=a*a%MOD;
        k>>=1;
    }
    return res;
}
ll inv(ll x){
    return pw(x,MOD-2);
}
void init(){
    mult[0]=1;
    for(ll i=1;i<=n;i++)mult[i]=mult[i-1]*i%MOD;
    inmult[n]=inv(mult[n]);
    for(ll i=n;i>=1;i--)inmult[i-1]=inmult[i]*i%MOD;
}
ll C(ll n,ll m){
    return mult[n]*inmult[n-m]%MOD*inmult[m]%MOD;
}
void solve(ll l,ll r){
    ll len=r-l+1;
    for(ll i=l;i<=r;i++){
        if(!st.empty()){
            if(st.top()==0&&s[i]==1){
                st.pop();
                continue;
            }
        }
        st.push(s[i]);
    }
    ll sum1=0,sum0=0,sum=0;
    while(!st.empty()){
        ll k=st.top();st.pop();
        if(k)sum1++;
        else sum0++;
        sum++;
    }
    ll ans=0;
    ll k=len-sum1-sum0;
    k/=2;
    ans=(C(len,k)-C(len,k-1)+MOD)%MOD;
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    init();
    for(ll i=1;i<=n;i++){
        char ch;cin>>ch;
        s[i]=ch-'0';
    }
    cin>>q;
    while(q--){
        ll op,l,r;
        cin>>op>>l>>r;
        if(op==1){
            for(ll i=l;i<=r;i++){
                s[i]=1-s[i];
            }
        }
        else{
            solve(l,r);
        }
    }
    return 0;
}