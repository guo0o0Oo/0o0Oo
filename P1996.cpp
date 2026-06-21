#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
list<ll> node;
ll n,k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(ll i=1;i<=n;i++)node.push_back(i);
    list<ll> ::iterator it=node.begin();
    while(node.size()){
        for(ll i=1;i<k;i++){
            it++;
            if(it==node.end())it=node.begin();
        }
        cout<<*it<<" ";
        list<ll> ::iterator nxt=++it;
        if(nxt==node.end())nxt=node.begin();
        node.erase(--it);
        it=nxt;
    }
    return 0;
}