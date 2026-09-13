#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll a[200],n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    ll sum1=0,sum2=0;
    for(ll i=1;i<=n;i++)cin>>a[i],sum1+=a[i];
    ll mn=sup;
    for(ll i=1;i<n;i++){
        sum1-=a[i];
        sum2+=a[i];
        mn=min(mn,abs(sum1-sum2));
    }
    cout<<mn;
    return 0;
}