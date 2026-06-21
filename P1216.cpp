#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e3+10;
ll n,a[N][N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=i;j++){
            cin>>a[i][j];
        }
    }
    for(ll i=n;i>=1;i--){
        for(ll j=1;j<=i;j++){
            a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
        }
    }
    cout<<a[1][1]<<"\n";
    return 0;
}