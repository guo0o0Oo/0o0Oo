#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll a[200010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    ll cnt=0;
    char ch;
    for(ll i=1;i<=n;i++){
        cin>>ch;
        if(ch=='8')cnt++;
    }
    cout<<min(cnt,n/11);
    return 0;
}