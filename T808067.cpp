#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,a[200010],ifc[200010],ans,cnt;
vector<ll> edge[200010];
pair<ll,ll> task[200010];
void dfs(ll now,ll fa){
    if(now!=1&&edge[now].size()==1){
        ans+=a[now];
        cnt++;
        ifc[now]=1;
        task[now]={now,a[now]};
        return;
    }
    for(ll i:edge[now]){
        if(i==fa)continue;
        dfs(i,now);
        if(task[now].second<task[i].second)task[now]=task[i];
    }
    if(a[now]<task[now].second){
        ifc[task[now].first]=0;
        ifc[now]=1;
        ans-=task[now].second;
        ans+=a[now];
        task[now]={now,a[now]};
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<n;i++){
        ll u,v;cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,0);
    cout<<ans<<" "<<cnt<<"\n";
    for(ll i=1;i<=n;i++){
        if(ifc[i])cout<<i<<" ";
    }
    return 0;
}