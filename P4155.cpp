#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=2e5+10;
struct soi{
    ll id,l,r;
    bool operator<(const soi &x)const{
        return l<x.l;
    }
}s[N*2];
ll n,n2,m,go[N*2][50],ans[N*2];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        s[i].id=i;
        cin>>s[i].l>>s[i].r;
        if(s[i].l>s[i].r)s[i].r+=m;
    }
    sort(s+1,s+n+1);
    n2=n;
    for(ll i=1;i<=n;i++){
        n2++;
        s[n2]=s[i];
        s[n2].l+=m;
        s[n2].r+=m;
    }
    ll nxt=1;
    for(ll i=1;i<=n2;i++){
        while(nxt<=n2&&s[nxt].l<=s[i].r)nxt++;
        go[i][0]=nxt-1;
    }
    for(ll i=1;(1<<i)<=n;i++){
        for(ll j=1;j<=n2;j++){
            go[j][i]=go[go[j][i-1]][i-1];
        }
    }
    for(ll i=1;i<=n;i++){
        ll len=s[i].l+m,cur=i,res=1;
        for(ll j=log2(N);j>=0;j--){
            ll pos=go[cur][j];
            if(pos&&s[pos].r<len){
                res+=1<<j;
                cur=pos;
            }
        }
        ans[s[i].id]=res+1;
    }
    for(ll i=1;i<=n;i++)cout<<ans[i]<<" ";
    return 0;
}