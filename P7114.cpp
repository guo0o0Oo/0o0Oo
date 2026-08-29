#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x)&-(x))
using ll=long long;
using pr=pair<ll,ll>;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
string s;
ll n,cnt[30],fc[2000010],fa[2000010],z[2000010],ans;
bool ask(ll l,ll k){
    if(l%k!=0)return 0;
    for(ll i=0;i<l;i++){
        if(s[i]!=s[i%k])return 0;
    }
    return 1;
}
void init(){
    ans=0;
    n=s.size();
    for(ll i=0;i<=29;i++)cnt[i]=0;
    for(ll p=n-1;p>=0;p--){
        cnt[s[p]-'a']++;
        if(cnt[s[p]-'a']&1)fc[p]=fc[p+1]+1;
        else fc[p]=fc[p+1]-1;
    }
    for(ll i=0;i<=29;i++)cnt[i]=0;
    fa[0]=1;
    cnt[s[0]-'a']++;
    for(ll p=1;p<=n;p++){
        cnt[s[p]-'a']++;
        if(cnt[s[p]-'a']&1)fa[p]=fa[p-1]+1;
        else fa[p]=fa[p-1]-1;
    }
    z[0]=0;
    ll l=0,r=0;
    for(ll i=1;i<n;i++){
        if(i<r){
            
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;	cin>>T;
    while(T--){
        cin>>s;
        init();
        if(s.size()<3){cout<<"0\n";continue;}
        for(ll l=2;l<=n-1;l++){//A+B.size
            
        }
        cout<<ans<<"\n";
    }
    return 0;
}