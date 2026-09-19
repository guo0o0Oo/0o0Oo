#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll N=1e4+10;
ll n,len[N],t[N],in[N];
vector<ll> G[N];
queue<ll> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)t[i]=0;
    for(ll i=1;i<=n;i++){
        ll u,v;
        cin>>u;
        cin>>len[u];
        while(1){
            cin>>v;
            if(v==0)break;
            G[v].push_back(u);
            in[u]++;
        }
    }
    for(ll i=1;i<=n;i++){
        if(in[i]==0)q.push(i);
    }
    ll last=-inf;
    while(!q.empty()){
        ll task=q.front();
        q.pop();
        last=max(last,t[task]+len[task]);
        for(ll i:G[task]){
            t[i]=max(t[i],t[task]+len[task]);
            in[i]--;
            if(in[i]==0)q.push(i);
        }
    }
    cout<<last<<"\n";
    return 0;
}