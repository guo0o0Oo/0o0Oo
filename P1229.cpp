#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
string s1,s2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s1>>s2;
    ll ans=1;
    for(ll i=0;i<s1.size()-1;i++){
        ll pos1=s2.find(s1[i]),pos2=s2.find(s1[i+1]);
        if(pos1==pos2+1)ans*=2;
    }
    cout<<ans<<"\n";
    return 0;
}