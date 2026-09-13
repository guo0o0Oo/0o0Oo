#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
string s;
ll ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s;
    for(ll i=0;i<s.size();i++){
        ll cnt=0;
        for(ll j=0;i+j<s.size()&&i-j>=0;j++){
            cnt+=s[i+j]!=s[i-j];
            if(cnt>1)break;
            ans++;
        }
    }
    for(ll i=0;i<s.size();i++){
        ll cnt=0;
        for(ll j=1;i+j<s.size()&&i-j+1>=0;j++){
            cnt+=s[i+j]!=s[i-j+1];
            if(cnt>1)break;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}