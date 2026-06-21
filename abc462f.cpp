#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll dp[20][4][2];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;	cin>>t;
    while(t--){
        string s;cin>>s;
        ll k;cin>>k;
        ll old=1,now=0;
        dp[0][0][0]=1;
        for(ll i=0;i<=k;i++)
            for(ll j=0;j<=3;j++)
                for(ll kk=0;kk<=1;kk++)
                    dp[i][j][kk]=sup;
        for(ll i=0;i<s.size();i++){
            swap(old,now);
            for(ll j=-1;j<=k;j++){
                for(ll kk=0;kk<=3;kk++){
                    dp[j][kk][now]=min(dp[j][kk][now],dp[j][kk][old])
                }
            }
        }
    }
    return 0;
}