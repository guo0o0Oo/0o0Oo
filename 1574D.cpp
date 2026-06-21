#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct VectorHash {
    size_t operator()(const std::vector<ll>& v) const {
        size_t hash = 0;
        for (ll i : v) {
            hash ^= std::hash<ll>()(i) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};
ll n,a[15][200010],c[15],m;
unordered_set<vector<ll>,VectorHash> ifnc,vis;
priority_queue<pair<ll,vector<ll>>> qe;
void bfs(){
    while(ifnc.count(qe.top().second)){
        vector<ll> k=qe.top().second;
        if(vis.count(k))continue;
        vis.insert(k);
        ll v=qe.top().first;
        for(ll i=1;i<=n;i++){
            if(k[i-1]==1)continue;
            v-=a[i][k[i-1]];
            k[i-1]--;
            v+=a[i][k[i-1]];
            qe.push({v,k});
            v-=a[i][k[i-1]];
            k[i-1]++;
            v+=a[i][k[i-1]];
        }
        qe.pop();
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>c[i];
        for(ll j=1;j<=c[i];j++){
            cin>>a[i][j];
        }
    }
    cin>>m;
    for(ll i=1;i<=m;i++){
        ll k;
        vector<ll> vr;
        for(ll j=1;j<=n;j++){
            cin>>k;
            vr.push_back(k);
        }
        ifnc.insert(vr);
    }
    vector<ll> fir;
    ll v=0;
    for(int i=1;i<=n;i++){
        fir.push_back(c[i]);
        v+=a[i][c[i]];
    }
    qe.push({v,fir});
    bfs();
    for(auto i:qe.top().second){
        cout<<i<<" ";
    }
    cout<<"\n";
    return 0;
}