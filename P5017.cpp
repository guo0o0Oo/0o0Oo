#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,m,a[1000],g[1000],sum[1000];
void input(){
    for(ll i=1;i<=500;i++)g[i]=sup;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    for(ll i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<"\n";
    for(ll i=1;i<=n;i++){
        if(a[i]-a[1]<m){
            g[i]=i*a[i]-sum[i];
        }
        else{
            for(ll j=1;a[i]-a[j]>=m;j++){
                g[i]=min(g[i],g[j]+(i-j)*a[i]-sum[i]+sum[j]);
            }
        }
    }
    for(ll i=1;i<=n;i++)cout<<g[i]<<" ";
    cout<<"\n";
    return 0;
}