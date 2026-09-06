#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll m,a[20010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;	cin>>T;
    while(T--){
        cin>>m;
        ll p=1,mx=inf,ans=0;
        for(ll i=1;i<=m;i++)cin>>a[i];
        for(ll i=1;i<=m;i++){
            mx=max(mx,a[i]);
            if(a[i]==1)p=i,ans++;
        }
        if(mx==1){cout<<m<<"\n";continue;}
        
    }
    return 0;
}