#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,up[100010],maxu,down[100010],maxd,h[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    memset(up,0x3f3f3f3f,sizeof(up));
    down[0]=0x3f3f3f3f3f3f3f3f;
    up[0]=0;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>h[i];
    }
    for(ll i=1;i<=n;i++){
        for(ll j=max(ll(0),i-17000);j<=maxu;j++){
            if(up[j]<h[i]){
                down[j+1]=max(h[i],down[j+1]);
                maxd=max(maxd,j+1);
            }
        }
        for(ll j=max(ll(0),i-17000);j<=maxd;j++){
            if(down[j]>h[i]){
                up[j+1]=min(h[i],up[j+1]);
                maxu=max(maxu,j+1);
            }
        }
        for(ll j=max(ll(0),i-17000);j<=maxu;j++){
            if(up[j]<h[i]){
                down[j+1]=max(h[i],down[j+1]);
                maxd=max(maxd,j+1);
            }
        }
        for(ll j=max(ll(0),i-17000);j<=maxd;j++){
            if(down[j]>h[i]){
                up[j+1]=min(h[i],up[j+1]);
                maxu=max(maxu,j+1);
            }
        }
    }
    cout<<max(maxu,maxd)<<"\n";
    return 0;
}