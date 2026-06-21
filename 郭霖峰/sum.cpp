#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,m,k,a[10010],data[2000010],ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
    cin>>n>>m>>k;
    for(ll i=1;i<=n;i++)cin>>a[i],data[a[i]]++;
    sort(a+1,a+n+1);
    for(ll i=1;i<=n-2;i++){
        if(a[i]>m)break;
        for(ll j=i+1;j<=n-1;j++){
            if(a[i]+a[j]>m)break;
            if(m-a[i]-a[j]<=a[j])break;
            if(data[m-a[i]-a[j]])ans++,ans%=k;
        }
    }
    cout<<ans%k<<"\n";
    return 0;
}