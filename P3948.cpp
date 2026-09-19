#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll N=8e4+10;
ll n,opt,Final,mod,mn,mx,a[N],c[N],sum[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>opt>>mod>>mn>>mx;
    while(opt--){
        char op;cin>>op;
        if(op=='A'){
            ll l,r,x;
            cin>>l>>r>>x;
            c[l]+=x;
            c[r+1]-=x;
        }
        else{
            ll l,r,ans=0;
            cin>>l>>r;
            for(ll i=1;i<=n;i++){
                a[i]=a[i-1]+c[i];
            }
            for(ll i=l;i<=r;i++){
                if(mn<=a[i]*i%mod&&a[i]*i%mod<=mx){
                    ans++;
                }
            }
            cout<<ans<<"\n";
        }
    }
    for(ll i=1;i<=n;i++){
        a[i]=a[i-1]+c[i];
        sum[i]=sum[i-1];
        if(mn<=a[i]*i%mod&&a[i]*i%mod<=mx){
            sum[i]++;
        }
    }
    cin>>Final;
    while(Final--){
        ll l,r;
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<"\n";
    }
    return 0;
}