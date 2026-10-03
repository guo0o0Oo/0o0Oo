#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,k,a[5000010];
ll fd(ll l,ll r,ll k){
    ll i=l,j=r,mid=a[(l+r)>>1];
    while(i<=j){
        while(a[i]<mid)i++;
        while(a[j]>mid)j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++;j--;
        }
    }
    if(k<=j)return fd(l,j,k);
    if(k>=i)return fd(i,r,k);
    return a[k];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(ll i=1;i<=n;i++)cin>>a[i];
    cout<<fd(1,n,k+1);
    return 0;
}