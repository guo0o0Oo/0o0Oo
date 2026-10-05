#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll w,n,a[30010],ifc[30010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>w>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    ll p=n,ans=0;
    for(ll i=1;i<=n;i++){
        if(ifc[i])continue;
        while(p>=1&&w-a[i]<a[p])p--;
        ifc[i]=1;
        if(p>=1){
            ifc[p]=1;
            p--;
        }
        ans++;
    }
    cout<<ans<<"\n";
    return 0;
}