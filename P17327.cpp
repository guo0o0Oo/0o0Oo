#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e6+10;
ll n,a[N];
vector<ll> pri;
bool not_prime[N];
void pre(){
    for(ll i=2;i<=N-10;i++){
        if(!not_prime[i]){
            pri.push_back(i);
        }
        for(ll j:pri){
            if(i*j>N)break;
            not_prime[i*j]=1;
            if(i%j==0)break;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    pre();
    cout<<pri.size();
    return 0;
}