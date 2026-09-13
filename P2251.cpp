#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,m,st[100010][20],a[100010],lg[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=2;i<=100000;i++)lg[i]=lg[i/2]+1;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++)st[i][0]=a[i];
    for(ll k=1;k<20;k++){
        for(ll i=1;i+(1<<k)-1<=n;i++){
            st[i][k]=min(st[i][k-1],st[i+(1<<(k-1))][k-1]);
        }
    }
    for(ll i=1;i+m-1<=n;i++){
        cout<<min(st[i][lg[m]],st[i+m-(1<<lg[m])][lg[m]])<<"\n";
    }
    return 0;
}