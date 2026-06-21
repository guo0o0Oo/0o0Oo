#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+10;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,k,a[N];
bool is_head[N];
set<ll> se;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    a[0]=sup;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++)
        if(a[i-1]>a[i])is_head[i]=1;
    ll start;
    bool flag;
    for(ll i=1;i<=n;i++){
        if(a[i]!=0)se.insert(0);
        if(is_head[i]){
            if(a[i]>0){
                se.insert(0);
                flag=0;
            }
            else{
                se.insert(1);
                flag=1;
            }
            start=i;
            continue;
        }
        if(flag){
            if(a[max(start,i-k+1)]!=0){
                flag=0;
                continue;
            }
            if(a[i]-a[i-1]>1){
                flag=0;
                continue;
            }
            if(a[i]-a[i-1]==1){
                se.insert(a[i]+1);
            }
        }
    }
    cout<<se.size();
    return 0;
}