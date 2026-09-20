#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,a[500010],f=-inf,s=-inf,t=-inf;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++){
        if(a[i]>=f){
            t=s;s=f;f=a[i];
        }
        else if(a[i]>=s){
            t=s;s=a[i];
        }
        else if(a[i]>t){
            t=a[i];
        }
        if(i>=3)cout<<t<<"\n";
    }
    return 0;
}