#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll N=1e6+10;
ll n,m,c,k,a[N],ifh[N],all,ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>c>>k;
    if(m==0&&k==64&&n){
        cout<<18446744073709551616-n<<"\n";
        return 0;
    }
    else if(m==0&&k==64){
        cout<<"18446744073709551616"<<"\n";
        return 0;
    }
    for(ll i=1;i<=n;i++)cin>>a[i],all|=a[i];
    ll p,q;
    for(ll i=1;i<=m;i++){
        cin>>p>>q;
        ifh[p]=1;
    }
    for(ll i=0;i<k;i++){
        if(!ifh[i]||all&1){
            ans++;
        }
        all>>=1ull;
    }
    cout<<(1ull<<ans)-n<<"\n";
    return 0;
}