#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,p[20],q[20],s[20],all=1,ans;
bool cmp(){
    ll flag=1;
    for(ll i=1;i<=n;i++){
        if(s[i]<p[i]){
            flag=0;
            break;
        }
        if(s[i]>p[i])break;
        if(i==n)flag=0;
    }
    for(ll i=1;i<=n;i++){
        if(s[i]>q[i]){
            flag=0;
            break;
        }
        if(s[i]<q[i])break;
        if(i==n)flag=0;
    }
    return flag;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>p[i];
    for(ll i=1;i<=n;i++)cin>>q[i];
    for(ll i=1;i<=n;i++)s[i]=i;
    for(ll i=1;i<=n;i++)all*=i;
    for(ll i=1;i<=all;i++){
        ans+=cmp();
        next_permutation(s+1,s+n+1);
    }
    cout<<ans;
    return 0;
}