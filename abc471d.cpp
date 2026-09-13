#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll q,v;
priority_queue<ll> pq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>q>>v;
    while(q--){
        ll x,y,z;
        cin>>x;
        if(x==1){
            cin>>y>>z;
            pq.push(z-y);
        }
        else{
            cin>>y;
            if(pq.empty()){cout<<"-1\n";continue;}
            cout<<min(v,pq.top()+y)<<"\n";
            pq.pop();
        }
    }
    return 0;
}