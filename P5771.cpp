#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,a[20],ans=2;
void find(ll k){
    ll b[20];
    for(ll i=1;i<=n;i++){
        if(k&(1<<(i-1))){
            b
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<(1<<n);i++){
        find(i);
    }
    return 0;
}