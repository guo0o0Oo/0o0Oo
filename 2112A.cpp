#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;	cin>>T;
    while(T--){
        ll a,x,y;
        cin>>a>>x>>y;
        if(a<x&&a<y||a>x&&a>y)cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}