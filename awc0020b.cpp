#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll tired=1;
ll n,m,s,d[200010],r[200010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>s;
    for(ll i=1;i<=n;i++){
        cin>>d[i];
    }
    ll p,a;
    for(ll i=1;i<=m;i++){
        cin>>p>>a;
        r[p]=a;
    }
    for(ll i=1;i<=n;i++){
        s-=tired*d[i];
        if(s<=0)tired=2;
        s+=r[i];
    }
    cout<<s<<"\n";
    return 0;
}