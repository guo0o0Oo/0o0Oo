#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,a[8010]={0,2,3,4,6,7};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("queue.in","r",stdin);
    freopen("queue.out","w",stdout);
    cin>>n;
    if(n<=5){
        cout<<a[n]<<"\n";
        return 0;
    }
    for(ll i=6;i<=n;i++){
        ll res=sup;
        for(ll j=1;j<i;j++){
            if(a[j]*2>a[i-1])res=min(res,a[j]*2);
            if(a[j]*3>a[i-1])res=min(res,a[j]*3);
            if(a[j]*7>a[i-1])res=min(res,a[j]*7);
        }
        a[i]=res;
    }
    cout<<a[n]<<"\n";
    return 0;
}