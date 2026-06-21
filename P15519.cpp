#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll a[10][10];
ll x[10],y[10];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(ll i=1;i<=4;i++){
        for(ll j=1;j<=4;j++){
            cin>>a[i][j];
            x[i]+=a[i][j];
            y[j]+=a[i][j];
        }
    }
    ll flag=0;
    for(ll i=1;i<=4;i++){
        if(x[i]!=x[1]||y[i]!=x[1]){
            flag=1;
            break;
        }
    }
    if(flag){
        cout<<"not magic\n";
    }
    else{
        cout<<"magic\n";
    }
    return 0;
}