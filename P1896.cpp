#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,k;
ll m,maxlen,sta[100];
ll dp[10][100][100];//行，最后一行，一共填多少
void init(ll siz){
    for(ll i=0;i<siz;i++){
        if(!(i&(i>>1))&&!(i&(i<<1))){
            sta[++m]=i;
        }
    }
    dp[0][1][0]=1;
}
ll cnt_sta(ll k){
    ll cnt=0;
    for(ll i=0;i<n;i++){
        if(sta[k]&(1<<i)){
            cnt++;
        }
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    if(n==1){
        cout<<1<<"\n";
        return 0;
    }
    init(1<<n);
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            ll cntj=cnt_sta(j);
            for(ll s=cntj;s<=k;s++){
                for(ll kk=1;kk<=m;kk++){
                    if(cnt_sta(j)+cnt_sta(kk)<=s){
                        if((sta[j]&sta[kk])||((sta[j]>>1)&sta[kk])||((sta[j]<<1)&sta[kk]))continue;;
                        dp[i][j][s]+=dp[i-1][kk][s-cnt_sta(j)];
                    }
                }
            }
        }
    }
    ll ans=0;
    for(ll i=1;i<=m;i++){
        ans+=dp[n][i][k];
    }
    cout<<ans;
    return 0;
}