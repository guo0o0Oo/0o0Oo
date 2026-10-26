#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m,q;
vector<ll> G[500010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=m;i++){
        ll a,b;cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cin>>q;
    while(q--){
        ll t,u,v;
        cin>>t;
        if(t==1){
            cin>>u>>v;
        }
        else if(t==2){
            cin>>u;
        }
        else if(t==3){
            cin>>u>>v;
        }
        else if(t==4){
            cin>>u;
        }
        cout<<"NO"<<"\n";
    }
    return 0;
}