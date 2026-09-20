#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n;
string s1,s2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    cin>>s1>>s2;
    ll ok=1;
    for(ll i=0;i<s1.size();i++){
        if(s2[i]!='*'&&s2[i]!=s1[i]){
            ok=0;
            break;
        }
    }
    if(ok){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}