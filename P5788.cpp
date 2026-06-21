#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=3e6+10;
ll n,a[N],o[N];
deque<ll> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=n;i>=1;i--){
        while(!q.empty()&&a[i]>=a[q.back()])q.pop_back();
        if(q.empty())o[i]=0;
        else o[i]=q.back();
        q.push_back(i);
    }
    for(ll i=1;i<=n;i++)cout<<o[i]<<" ";
    return 0;
}