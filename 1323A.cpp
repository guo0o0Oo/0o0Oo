#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll a[1000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;	cin>>t;
    while(t--){
        ll n;
        ll dan=0,shuang=0,stop=0;
        cin>>n;
        for(ll i=1;i<=n;i++){
            ll k;
            cin>>k;
            if(stop)continue;
            if(k&1){
                if(dan){
                    cout<<2<<"\n"<<dan<<" "<<i<<"\n";
                    stop=1;
                }
                else{
                    dan=i;
                }
            }
            else{
                cout<<1<<"\n"<<i<<"\n";
                stop=1;
            }
        }
        if(!stop){
            cout<<-1<<"\n";
        }
    }
    return 0;
}