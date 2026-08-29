#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
string s,t;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;	cin>>T;
    while(T--){
        cin>>s>>t;
        ll mx,now,ans=0;
        for(ll i=0;i<s.size();i++){
            now=i;
            for(ll j=0;j<t.size();j++){
                if(s[now]==t[j])now++;
                if(now>=s.size())break;
            }
            ans+=now-i;
        }
        cout<<ans<<"\n";
    }
    return 0;
}