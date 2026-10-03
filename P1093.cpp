#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using par=pair<pair<ll,ll>,ll>;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n;
par child[310];
bool cmp(const par& a,const par& b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    else{
        return a>b;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll a,b,c;cin>>a>>b>>c;
        child[i].first.first=a+b+c;
        child[i].first.second=a;
        child[i].second=i;
    }
    sort(child+1,child+n+1,cmp);
    for(ll i=1;i<=5;i++){
        cout<<child[i].second<<" "<<child[i].first.first<<"\n";
    }
    return 0;
}