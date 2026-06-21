#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
string str;
ll n,now=-1;
deque<ll> s,l,k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>str;
    for(ll i=1;i<=n;i++){
        if(i==n){
            k.push_back(i);
            while(!k.empty()){
                l.push_front(k.back());
                k.pop_back();
            }
            break;
        }
        k.push_back(i);
        if(str[i-1]>str[i]){
            while(!k.empty()){
                s.push_back(k.front());
                k.pop_front();
            }
        }
        if(str[i-1]<str[i]){
            while(!k.empty()){
                l.push_front(k.back());
                k.pop_back();
            }
        }
    }
    for(auto i:s){
        cout<<i<<" ";
    }
    for(auto i:l){
        cout<<i<<" ";
    }
    return 0;
}