#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=2020;
ll n,a[N],lis[N][N],lds[N][N],uph[N],dnh[N],dp[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n+10;j++)uph[j]=sup;
        uph[0]=inf;
        for(ll j=i;j<=n;j++){
            ll upl=lower_bound(uph,uph+n+1,a[j])-uph-1;
            lis[i][j]=upl+1;
            uph[upl+1]=min(uph[upl+1],a[j]);
        }
    }
    for(ll i=n;i>=1;i--){
        for(ll j=1;j<=n+10;j++)dnh[j]=sup;
        dnh[0]=inf;
        for(ll j=i;j>=1;j--){
            ll dnl=lower_bound(dnh,dnh+n+1,a[j])-dnh-1;
            lds[j][i]=dnl+1;
            dnh[dnl+1]=min(dnh[dnl+1],a[j]);
        }
    }
    for(ll i=1;i<=n;i++)dp[i]=inf;
    for(ll i=1;i<=n;i++){
        dp[i]=0;
        for(ll j=1;j<=i;j++){
            ll l=j,r=i;
            while(r-l>30){
                ll k=(r-l)/3;
                ll mid1=l+k,mid2=r-k;
                if(min(lis[j][mid1],lds[mid1][i])>min(lis[j][mid2],lds[mid2][i]))r=mid2;
                else l=mid1;
            }
            for(ll k=l;k<=r;k++)
                if(min(lis[j][k],lds[k][i])>1)
                    dp[i]=max(dp[i],dp[j-1]+min(lis[j][k],lds[k][i])*2-1);
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}