#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,q,l[300010],r[300010],s,t,stl[300010][20],str[300010][20],lg2[300010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    lg2[1]=0;
    for(ll i=2;i<=300010;i++)lg2[i]=lg2[i/2]+1;
    cin>>n>>q;
    for(ll i=2;i<=n;i++){
        cin>>l[i];
    }
    for(ll i=1;i<=n-1;i++){
        cin>>r[i];
    }
    for(ll i=1;i<=n;i++){
        stl[i][0]=l[i];
        str[i][0]=r[i];
    }
    for(ll k=1;k<=lg2[n];k++){
        for(ll i=1;i+(1ll<<k)-1<=n;i++){
            stl[i][k]=min(stl[i][k-1],stl[i+(1ll<<(k-1))][k-1]);
            str[i][k]=min(str[i][k-1],str[i+(1ll<<(k-1))][k-1]);
        }
    }
    while(q--){
        cin>>t>>s;
        ll ans;
        if(s<t){
            if(t==n){
                cout<<l[t]<<"\n";
                continue;
            }
            ans=min(l[t],r[t]+min(stl[t+1][lg2[n-t]],stl[n-(1ll<<lg2[n-t])+1][lg2[n-t]]));
        }
        else{
            if(t==1){
                cout<<r[t]<<"\n";
                continue;
            }
            ans=min(r[t],l[t]+min(str[1][lg2[t-1]],str[t-(1ll<<lg2[t-1])][lg2[t-1]]));
        }
        cout<<ans<<"\n";
    }
    return 0;
}