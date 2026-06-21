#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD1=1e6+7;
const int MOD2=2e4-3;
const int MOD3=1e9+7;
ll n,m,k1[110],k2[110],k3[110],ans[1000010];
ll str_mod(const string& s, int mod) {
    long long res = 0;
    bool neg = false;
    int start = 0;
    if (s[0] == '-') {
        neg = true;
        start = 1;
    }
    for (int i = start; i < s.size(); i++) {
        res = (res * 10 + (s[i] - '0')) % mod;
    }
    if (neg) res = (mod - res) % mod;
    return res;
}
bool check(int x){
    ll res1=0;
    ll res2=0;
    ll res3=0;
    for(int i=n;i>=1;i--){
        res1*=x;
        res2*=x;
        res3*=x;
        res1+=k1[i];
        res2+=k2[i];
        res3+=k3[i];
        res1%=MOD1;
        res2%=MOD2;
        res3%=MOD3;
    }
    if(res1==res2&&res2==res3&&res3==0){
        return 1;
    }
    return 0;
}
int main(){
    cin>>n>>m;
    n++;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        k1[i]=str_mod(s,MOD1);
        k2[i]=str_mod(s,MOD2);
        k3[i]=str_mod(s,MOD3);
    }
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(check(i)){
            ans[++cnt]=i;
        }
    }
    cout<<cnt<<"\n";
    for(int i=1;i<=cnt;i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}