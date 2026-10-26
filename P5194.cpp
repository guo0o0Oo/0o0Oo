#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,c,a[2000],ans,sum[2000],cnt;
void dfs(ll dep){
    ans=max(ans,cnt);
    if(cnt+sum[dep]<=c){
        ans=max(ans,cnt+sum[dep]);
        return;
    }
    if(cnt+a[dep]>c){
        dfs(dep-1);
        return;
    }
    cnt+=a[dep];
    dfs(dep-1);
    cnt-=a[dep];
    dfs(dep-1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>c;
    for(ll i=1;i<=n;i++)cin>>a[i],sum[i]=sum[i-1]+a[i];
    dfs(n);
    cout<<ans<<"\n";
    return 0;
}