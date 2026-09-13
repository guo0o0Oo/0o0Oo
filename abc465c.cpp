#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n;
string s;
deque<ll> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>s;
    ll now=0;
    for(ll i=0;i<n;i++){
        if(now==0){
            q.push_back(i+1);
        }
        else{
            q.push_front(i+1);
        }
        if(s[i]=='o')now=1-now;
    }
    if(now==1){
        while(!q.empty()){
            cout<<q.back()<<" ";
            q.pop_back();
        }
    }
    else{
        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop_front();
        }
    }
    return 0;
}