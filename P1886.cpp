#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e6+10;
ll n,k,a[N];
deque<ll> dq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++){
        while(!dq.empty()&&a[dq.back()]>a[i])dq.pop_back();
        dq.push_back(i);
        if(i>=k){
            while(!dq.empty()&&dq.front()<=i-k)dq.pop_front();
            cout<<a[dq.front()]<<" ";
        }
    }
    cout<<"\n";
    while(!dq.empty())dq.pop_front();
    for(ll i=1;i<=n;i++){
        while(!dq.empty()&&a[dq.back()]<a[i])dq.pop_back();
        dq.push_back(i);
        if(i>=k){
            while(!dq.empty()&&dq.front()<=i-k)dq.pop_front();
            cout<<a[dq.front()]<<" ";
        }
    }
    cout<<"\n";
    return 0;
}