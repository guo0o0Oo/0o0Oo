#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=2e5+10;
ll n,m,k,a[N],ifc[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(ll i=1;i<=n;i++)cin>>a[i];
    ll l=1,sum=0;
    for(ll i=1;i<=n;i++){
        while(i-l+1>m){
            sum-=ifc[l]*a[l];
            l++;
        }
        if(sum+a[i]<=k){
            cout<<"Yes\n";
            ifc[i]=1;
            sum+=a[i];
        }
        else cout<<"No\n";
    }
    return 0;
}