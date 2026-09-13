#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n;
string s[200];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>s[i];
        for(ll j=0;j<s[i].size();j++)if(s[i][j]>='A'&&s[i][j]<='Z')s[i][j]+='a'-'A';
    }
    sort(s+1,s+n+1);
    ll cnt=0,mx=0;
    for(ll i=1;i<=n;i++){
        if(s[i]==s[i-1]){
            cnt++;
        }
        else{
            cnt=1;
        }
        mx=max(mx,cnt);
    }
    cout<<mx;
    return 0;
}