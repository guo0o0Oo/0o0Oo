#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll N=510;
ll n,a[N][N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n-1;i++){
        for(ll j=i+1;j<=n;j++){
            cin>>a[i][j];
            a[j][i]=a[i][j];
        }
    }
    ll fi=-inf,se=-inf,mx=-inf;
    for(ll i=1;i<=n;i++){
        fi=-inf,se=-inf;
        for(ll j=1;j<=n;j++){
            if(a[i][j]>=fi){
                se=fi;
                fi=a[i][j];
            }
            else if(a[i][j]>se){
                se=a[i][j];
            }
        }
        mx=max(mx,se);
    }
    cout<<1<<"\n"<<mx<<"\n";
    return 0;
}