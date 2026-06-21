#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll MOD=1e9+7;
ll n,m,a[110],t[110],cnt[110][110],l[110][110][110];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    while(m--){
        ll w;cin>>w;
        memset(cnt,0,sizeof(cnt));
        memset(l,0,sizeof(l));
        for(ll i=1;i<=n;i++)
        for(ll j=1;j<=w;j++)l[i][j][0]=1;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=w;j++){
                cnt[i][j]+=cnt[i-1][j];
                if(w>=a[i]){
                    for(ll k=0;k<=w;k++)
                        if(l[i-1][j][k])
                            cnt[i][j]+=l[i-1][j][k]*(k+1);
                }
                cnt[i][j]%=MOD;
                for(ll k=0;k<=w;k++){
                    l[i][j][k]=
                }
            }
        }
    }
    for(ll i=1;i<=m;i++)cin>>t[i];
    for(ll i=1;i<=m;i++){
        
        for(ll j=0;j<=n;j++)
        for(ll k=0;k<=t[i];k++)l[j][k][0]=1;
        for(ll j=1;j<=n;j++){
            for(ll k=1;k<=t[i];k++){
                cnt[j][k]+=cnt[j-1][k];
                if(k>=a[j]){
                    ll s=0;
                    for(ll o=0;o<=t[i];o++)if(l[j-1][k-a[j]][o])s+=l[j-1][k-a[j]][o]*(o+1);
                    cnt[j][k]+=s;
                }
                cnt[j][k]%=MOD;
                for(ll o=1;o<=t[i];o++){
                    l[j][k][o]+=l[j-1][k][o];
                    if(k>=a[j])l[j][k][o]+=l[j-1][k-a[j]][o-1]*(o+1);
                }
            }
        }
        for(ll j=1;j<=n;j++){
            for(ll k=1;k<=t[i];k++){
                cout<<cnt[j][k]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        cout<<cnt[n][t[i]]<<"\n";
    }
    return 0;
}