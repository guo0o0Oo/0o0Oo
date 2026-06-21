#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll a[50010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;	cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(ll i=1;i<=n;i++)cin>>a[i];
        if(a[n]>=a[1]+a[2]){
            cout<<"1 2 "<<n<<"\n";
        }
        else cout<<-1<<"\n";
    }
    return 0;
}