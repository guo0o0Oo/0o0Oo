#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,k,a[200010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;	cin>>T;
    while(T--){
        cin>>n>>k;
        if(n==1&&k==0){
            cout<<1<<"\n";
            continue;
        }
        else if(n==1){
            cout<<-1<<"\n";
            continue;
        }
        else if(k==0){
            for(ll i=1;i<=n;i++)cout<<1<<" ";
            cout<<"\n";
            continue;
        }
        else if(k==1){
            cout<<-1<<"\n";
            continue;
        }
        else if(k<=1000000000){
            cout<<1<<" "<<k<<" ";
            for(ll i=1;i<=n-2;i++)cout<<1<<" ";
            cout<<"\n";
        }
        else cout<<-1<<"\n";
    }
    return 0;
}