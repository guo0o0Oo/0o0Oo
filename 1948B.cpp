#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,a[1000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;	cin>>T;
    while(T--){
        cin>>n;
        ll flag=1;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        ll mn=inf;
        for(ll i=n;i>=1;i--){
            if(mn>=a[i]){
                mn=a[i];
                continue;
            }
            while(a[i]){
                if(a[i]%10>mn){
                    flag=0;
                    break;
                }
                mn=a[i]%10;
                a[i]/=10;
            }
        }
        if(flag){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}