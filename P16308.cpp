#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
string s;
ll tr(char c){
    if(c=='('||c==')')return 0;
    else if(c=='['||c==']') return 1;
    else return -2;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;	cin>>t;
    while(t--){
        cin>>s;
        ll cnt=0;
        for(ll i=1;i<s.size();i++){
            if(tr(s[i])==tr(s[i-1]))cnt++;
        }
        if(cnt>2)cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
}