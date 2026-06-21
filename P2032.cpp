#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,m,a[2000010];
deque<ll> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++){
        while(!q.empty()&&a[q.back()]<=a[i])q.pop_back();
        while(!q.empty()&&q.front()<i-m+1)q.pop_front();
        q.push_back(i);
        if(i>=m)cout<<a[q.front()]<<"\n";
    }
    return 0;
}