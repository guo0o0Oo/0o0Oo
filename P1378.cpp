#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,ll>;
const ll inf=0x3f3f3f3f3f3f3f3f;
const double pi=acos(-1.0);
ll n;
ll x,y,xx,yy;
double ans,r[10];
pr pos[10];
bool ifc[10];
double dis(pr a,pr b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
void dfs(ll dep){
    if(dep==n+1){
        double sum=0;
        for(ll i=1;i<=n;i++)sum+=r[i]*r[i];
        ans=max(ans,pi*sum);
        return;
    }
    for(ll i=1;i<=n;i++){
        if(!ifc[i]){
            double l=min({fabs(x-pos[i].first),fabs(xx-pos[i].first),fabs(y-pos[i].second),fabs(yy-pos[i].second)});
            for(ll j=1;j<=n;j++){
                if(ifc[j]){
                    l=min(l,max(0.0,dis(pos[i],pos[j])-r[j]));
                }
            }
            r[i]=l;
            ifc[i]=1;
            dfs(dep+1);
            ifc[i]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    cin>>x>>y>>xx>>yy;
    for(ll i=1;i<=n;i++)cin>>pos[i].first>>pos[i].second;
    dfs(1);
    ll res=fabs(x-xx)*fabs(y-yy)-ans+0.5;
    cout<<res;
    return 0;
}