#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,a[110];
ll k[110][2],cnt;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;	cin>>t;
    while(t--){
        cin>>n;
        for(ll i=1;i<=n;i++)cin>>a[i];
        cnt=0;
        for(ll i=1;i<=n;i++){
            if(a[i]!=i){
                for(ll j=n;j>=1;j--){
                    if(a[i]>a[j]){
                        k[++cnt][0]=i;
                        k[cnt][1]=j;
                        sort(a+i,a+j+1);
                        break;
                    }
                }
            }
        }
        cout<<cnt<<"\n";
        for(ll i=1;i<=cnt;i++){
            cout<<k[i][0]<<" "<<k[i][1]<<"\n";
        }
    }
    return 0;
}