#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,k,fa[50010],w[50010],ans;
void init(){
    for(ll i=1;i<=n;i++)fa[i]=i;
}
ll fd(ll x){
    if(fa[x]==x)return x;
    ll p=fa[x];
    fa[x]=fd(p);
    w[x]=(w[x]+w[p]+3)%3;
    return fa[x];
}
void mg(ll x,ll y,ll v){
    ll fx=fd(x),fy=fd(y);
    if(fx==fy){
        if((w[x]-w[y]+3)%3!=v)ans++;
        return;
    }
    fa[fx]=fy;
    w[fx]=(v+w[y]-w[x]+3)%3;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    init();
    for(ll i=1;i<=k;i++){
        ll op,x,y;
        cin>>op>>x>>y;
        if(x>n||y>n){
            ans++;
            continue;
        }
        if(op==1){
            mg(x,y,0);
        }
        else{
            if(x==y){
                ans++;
                continue;
            }
            mg(x,y,1);
        }
    }
    cout<<ans<<"\n";
    return 0;
}