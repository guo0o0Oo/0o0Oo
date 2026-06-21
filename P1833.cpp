#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+10;
ll n,t,dp[N];
ll w[N],c[N],m[N];
ll c_n,c_dp[N];
ll c_w[N],c_c[N],c_m[N];
ll new_n;
ll new_w[N],new_c[N],new_m[N];
int main(){
    int x1,y1,x2,y2;
    scanf("%d:%d %d:%d %d",&x1,&y1,&x2,&y2,&n);
    t=(x2-x1)*60+(y2-y1);
    for(ll i=1;i<=n;i++){
        cin>>c[i]>>w[i]>>m[i];
        if(m[i]==0){
            c_c[++c_n]=c[i];
            c_w[c_n]=w[i];
        }
    }
    for(ll i=1;i<=n;i++){
        for(int j=1;j<=m[i];j<<=1){
            m[i]-=j;
            new_c[++new_n]=j*c[i];
            new_w[new_n]=j*w[i];
        }
        if(m[i]){
            new_c[++new_n]=m[i]*c[i];
            new_w[new_n]=m[i]*w[i];
        }
    }
    for(ll i=1;i<=c_n;i++){
        for(ll j=c_c[i];j<=t;j++){
            c_dp[j]=max(c_dp[j],c_dp[j-c_c[i]]+c_w[i]);
        }
    }
    dp[0]=0;
    for(ll i=1;i<=t;i++)dp[i]=c_dp[i];
    for(ll i=1;i<=new_n;i++){
        for(ll j=t;j>=new_c[i];j--){
            dp[j]=max(dp[j],dp[j-new_c[i]]+new_w[i]);
        }
    }
    cout<<dp[t]<<"\n";
    return 0;
}