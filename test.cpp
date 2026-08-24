#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,m,a[100][100],l[100];
void swp(ll x,ll y,ll a,ll b){
    if(y==b){
        ll dat=1+y%n;
        for(ll i=1;i<=a-1;i++)cout<<y<<" "<<n+1<<"\n";
        cout<<dat<<" "<<n+1<<"\n";
        cout<<y<<" "<<dat<<"\n";
        for(ll i=a+1;i<=x;i++)cout<<y<<" "<<n+1<<"\n";
        cout<<dat<<" "<<y<<"\n";
        cout<<n+1<<" "<<dat<<"\n";
        for(ll i=1;i<=x-a-1;i++)cout<<n+1<<" "<<y<<"\n";
        cout<<dat<<" "<<y<<"\n";
        cout<<n+1<<" "<<dat<<"\n";
        for(ll i=1;i<=a-1;i++)cout<<n+1<<" "<<y<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    n=10;
    m=20;
    swp(8,1,3,1);
    cout<<"\n";
    swp(3,1,1,1);
    return 0;
}