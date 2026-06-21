#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=2e5+10;
struct gm{
    ll num,s,w;
}psn[N],s1[N],s2[N];
ll n,r,q;
bool cmp(gm a,gm b){
    if(a.s==b.s)return a.num<b.num;
    return a.s>b.s;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>r>>q;
    n*=2;
    for(ll i=1;i<=n;i++)psn[i].num=i;
    for(ll i=1;i<=n;i++)cin>>psn[i].s;
    for(ll i=1;i<=n;i++)cin>>psn[i].w;
    sort(psn+1,psn+n+1,cmp);
    while(r--){
        ll cnt=0;
        for(ll i=1;i<=n;i+=2){
            if(psn[i].w>psn[i+1].w)psn[i].s++,s1[++cnt]=psn[i],s2[cnt]=psn[i+1];
            else psn[i+1].s++,s1[++cnt]=psn[i+1],s2[cnt]=psn[i];
        }
        ll i=1,j=1,k=1;
        while(i<=cnt&&j<=cnt){
            if(s1[i].s>s2[j].s||(s1[i].s==s2[j].s&&s1[i].num<s2[j].num))psn[k++]=s1[i++];
            else psn[k++]=s2[j++];
        }
        while(i<=cnt)psn[k++]=s1[i++];
        while(j<=cnt)psn[k++]=s2[j++];
    }
    cout<<psn[q].num<<"\n";
    return 0;
}