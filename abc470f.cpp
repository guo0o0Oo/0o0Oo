#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=2e5+10;
ll n,m,a,b,cnt[27],c[N];
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for(ll i=1;i<=m;i++){
        cin>>a>>b;
        if(!c[a]){
            c[a]=1;
            cnt[s[a-1]-'a']++;
        }
        if(!c[b]){
            c[b]=1;
            cnt[s[b-1]-'a']++;
        }
    }

    return 0;
}