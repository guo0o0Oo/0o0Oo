/*
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=15;
ll ten[N],dp[N];
ll cnta[N],cntb[N];
ll num[N];
void init(){
    ten[0]=1;
    for(ll i=1;i<=N;i++){
        dp[i]=i*ten[i-1];
        ten[i]=10*ten[i-1];
    }
}
void solve(ll x,ll *cnt){
    ll len=0;
    while(x){
        num[++len]=x%10;
        x/=10;
    }
    for(ll i=len;i>=1;i--){
        for(ll j=0;j<=9;j++)cnt[j]+=num[i]*dp[i-1];
        for(ll j=0;j<num[i];j++)cnt[j]+=ten[i-1];
        ll num2=0;
        for(ll j=i-1;j>=1;j--)num2=num2*10+num[j];
        cnt[num[i]]+=num2+1;
        cnt[0]-=ten[i-1];
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    init();
    ll a,b;
    cin>>a>>b;
    solve(a-1,cnta);
    solve(b,cntb);
    for(ll i=0;i<=9;i++)cout<<cntb[i]-cnta[i]<<" ";
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=15;
ll dp[N][N];
ll num[N],now;
ll dfs(ll pos,ll sum,bool lead,bool limit){
    ll ans=0;
    if(pos==0)return sum;
    if(!lead&&!limit&&dp[pos][sum]!=-1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    return 0;
}