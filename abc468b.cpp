#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll m,d,ans,flag;
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>m>>d;
    cin>>s;
    for(ll i=0;i<s.size();i++){
        flag=1;
        for(ll j=max(0ll,i-d);j<=min(i+d,ll(s.size()));j++){
            if(s[j]=='G'){
                flag=0;
                break;
            }
        }
        ans+=flag;
    }
    cout<<ans;
    return 0;
}