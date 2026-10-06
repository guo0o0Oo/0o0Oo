#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,a[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;	cin>>T;
    while(T--){
        cin>>n;
        for(ll i=1;i<=n;i++)cin>>a[i];
        ll cnt=0;
        for(ll i=1;i<=n;i++){
            if(a[i]==0)continue;
            ll j=i+1;
            while(j<=n&&(a[i]&a[j])==a[i]){
                a[j]-=a[i];
                j++;
            }
            a[i]=0;
            cnt++;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}