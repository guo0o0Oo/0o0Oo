#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,ll>;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    cout<<"Yes"<<"\n";
    for(ll i=1;i<=n;i++)cout<<3*i<<" ";
    cout<<"\n";
    for(ll i=1;i<=n;i++)cout<<3*i+1<<" ";
    cout<<"\n";
    return 0;
}