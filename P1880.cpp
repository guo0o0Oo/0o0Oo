#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,a[110],mindp[110][110],maxdp[110][110],sum[110][110],minans=sup,maxans=inf;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll t=0;t<=n;t++){
        ll s=a[1];
        for(ll i=1;i<=n;i++)a[i]=a[i+1];
        a[n]=s;
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=n-i+1;j++)
                sum[i][j]=sum[i][j-1]+a[i+j-1];
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=n;j++)
                mindp[i][j]=sup,maxdp[i][j]=inf;
        for(ll j=1;j<=n;j++){
            for(ll i=1;i<=n-j+1;i++){
                if(j==1){mindp[i][j]=0;maxdp[i][j]=0;continue;}
                for(ll k=1;k<j;k++){
                    mindp[i][j]=min(mindp[i][k]+mindp[i+k][j-k]+sum[i][j],mindp[i][j]);
                    maxdp[i][j]=max(maxdp[i][k]+maxdp[i+k][j-k]+sum[i][j],maxdp[i][j]);
                }
            }
        }
        minans=min(mindp[1][n],minans);
        maxans=max(maxdp[1][n],maxans);
    }
    cout<<minans<<"\n"<<maxans<<"\n";
    return 0;
}