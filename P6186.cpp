#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,m,a[200010],b[200010];
ll solve(ll k){
    for(ll i=1;i<=n;i++)b[i]=a[i];
    for(ll i=1;i<=k;i++){
        for(ll j=1;j<n;j++){
            if(b[j]>b[j+1])swap(b[j],b[j+1]);
        }
    }
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=m;i++){
        ll b,c;
        cin>>b>>c;
        if(b==1){
            swap(a[c],a[c+1]);
        }
        else{

        }
    }
    return 0;
}