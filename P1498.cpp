#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n;
string s[2000];
void print(ll k,ll x){
    if(k==1){
        s[x-1]+=" /\\ ";
        s[x]+="/__\\";
        return;
    }
    print(k-1,x);
    print(k-1,x);
    for(ll i=x-(1<<k)+1;i<=x-(1<<(k-1));i++)
        for(ll j=x-(1<<k)+1;j<=x-(1<<(k-1));j++)
            s[i]+=' ';
    print(k-1,x-(1<<(k-1)));
    for(ll i=x-(1<<k)+1;i<=x-(1<<(k-1));i++)
        for(ll j=x-(1<<k)+1;j<=x-(1<<(k-1));j++)
            s[i]+=' ';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    print(n,(1<<n));
    for(ll i=1;i<=(1<<n);i++){
        cout<<s[i]<<"\n";
    }
    return 0;
}