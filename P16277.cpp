#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,a;
bool is_p(ll k){
    ll rek=0,x=k;
    while(x!=0)rek=rek*10+x%10,x/=10;
    if(rek==k)return 1;
    else return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a;
        ll k=1;
        bool flag=1;
        while(a>=k){
            if(is_p(a-k)){
                flag=0;
                cout<<"Yes\n";
                break;
            }
            k<<=1;
        }
        if(flag){
            cout<<"No\n";
        }
    }
    return 0;
}