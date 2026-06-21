#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll a[1000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll k,i=0;
    a[i]=inf;
    while(a[i]!=0){
        cin>>k;
        i++;
        a[i]=k;
    }
    for(i=i-1;i>=1;i--)cout<<a[i]<<" ";
    return 0;
}