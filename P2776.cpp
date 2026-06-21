#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e5+10;
ll n,m,t,g[N];
deque<ll> q;
deque<ll> cla[310];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=0;i<n;i++)cin>>g[i];
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(s=="push"){
            ll k;
            cin>>k;
            if(cla[g[k]].size()==0)q.push_back(g[k]);
            cla[g[k]].push_back(k);
        }
        else{
            cout<<cla[q.front()].front()<<"\n";
            cla[q.front()].pop_front();
            if(cla[q.front()].size()==0)q.pop_front();
        }
    }
    return 0;
}