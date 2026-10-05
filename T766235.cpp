#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll MOD=1e9+7;
ll n,k,pre[3010],inv[3010],ans[3010][3010];
string s;
ll pw(ll a,ll x){
    ll res=1;
    while(x){
        if(x&1)res=res*a%MOD;
        a=a*a%MOD;
        x>>=1;
    }
    return res;
}
ll C(ll a,ll b){
    return pre[a]*inv[a-b]%MOD*inv[b]%MOD;
}
void init(){
    pre[0]=1;
    for(ll i=1;i<=3000;i++)pre[i]=pre[i-1]*i%MOD;
    inv[3000]=pw(pre[3000],MOD-2);
    for(ll i=2999;i>=0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    init();
    
    ll T;	cin>>T;
    while(T--){
        cin>>n>>k>>s;
        ll p=1;
        for(ll i=s.size()-1;i>=0;i--){
            if(s[i]=='1')break;
            p++;
        }
        ll ans=0;
        for(ll i=0;i<=min(p-1,k);i++){
            for(ll j=0;j<=min(k-i,p-1-i);j++){
                ans=(ans+C(p-1-i,j))%MOD;
            }
            if(i!=0)ans=(ans+max(p-1-k,0ll))%MOD;
        }
        cout<<ans<<" ";
        cout<<"\n";
    }
    return 0;
}