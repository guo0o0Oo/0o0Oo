#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,s[100010],cnt;
pair<ll,ll> a[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    ll zero=0;
    for(ll i=1;i<=n;i++)cin>>s[i],cnt+=s[i];
    if(cnt!=2*(n-1)){
        cout<<-1<<"\n";
        return 0;
    }
    for(ll i=1;i<=n;i++)a[i]={s[i],i};
    sort(a+1,a+n+1);
    ll pos=1;
    for(ll i=1;i<=n;i++){
        if(a[i].first!=1){
            pos=i;
            break;
        }
    }
    for(ll i=1;i<=n-2;i++){
        cout<<a[i].second<<" "<<a[pos].second<<"\n";
        a[pos].first--;
        if(a[pos].first==1)pos++;
    }
    cout<<a[n-1].second<<" "<<a[n].second;
    return 0;
}