#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll ans=0;
void dfs(ll res,ll mi,ll resk){
    if(resk==0&&res==0)ans++;
    if(resk<1||res<1)return;
    for(ll i=mi;i<=res;i++)dfs(res-i,i,resk-1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,k;
    cin>>n>>k;
    dfs(n,1,k);
    cout<<ans<<"\n";
    return 0;
}