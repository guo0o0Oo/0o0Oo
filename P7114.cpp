#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x)&-(x))
using ll=long long;
using pr=pair<ll,ll>;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
string s;
ll cnt[30],fc[2000010],fa[2000010],ans;
bool ask(ll l,ll k){
    if(l%k!=0)return 0;
    for(ll i=0;i<l;i++){
        if(s[i]!=s[i%k])return 0;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;	cin>>T;
    while(T--){
        cin>>s;
        ans=0;
        if(s.size()<3){cout<<"0\n";continue;}
        ll n=s.size();
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
        for(ll l=2;l<=n-1;l++){//(A+B)^i.size
            for(ll j=2;j<=l;j++){//A+B.size
                if(ask(l,j)){
                    for(ll k=1;k<=j-1;k++){//A.size
                        if(fa[k-1]<=fc[l]){
                            ans++;
                        }
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}