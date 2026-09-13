#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,m,a[1010][1010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    while(m--){
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        a[x1][y1]++;
        a[x2+1][y1]--;
        a[x1][y2+1]--;
        a[x2+1][y2+1]++;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}