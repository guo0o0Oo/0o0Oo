#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a[110],dp[110][2];
void solve(int k,bool p){//0:<-   1:->
    if(dp[k][p]!=-1)return ;
    if(p==0){
        dp[k][p]=0;
        for(int i=1;i<k;i++){
            if(a[i]<a[k]){
                solve(i,p);
                dp[k][p]=max(dp[k][p],dp[i][p]+1);
            }
        }
    }
    else{
        dp[k][p]=0;
        for(int i=n;i>k;i--){
            if(a[i]<a[k]){
                solve(i,p);
                dp[k][p]=max(dp[k][p],dp[i][p]+1);
            }
        }
    }
}
int main(){
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=n;
    for(int i=1;i<=n;i++){
        solve(i,0);
        solve(i,1);
        ans=min(ans,n-(dp[i][0]+dp[i][1]+1));
    }
    cout<<ans;
    return 0;
}