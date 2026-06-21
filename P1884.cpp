#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
struct rect{
    ll x1,y1,x2,y2;
}rec[1010];
bool cmp(const rect& a,const rect& b){
    return a.x1<b.x1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>rec[i].x1>>rec[i].y1>>rec[i].x2>>rec[i].y2;
    }
    sort(rec+1,rec+n+1,cmp);
    ll sum=0,cut=0;
    for(ll i=1;i<=n;i++){
        sum+=(rec[i].x2-rec[i].x1)*(rec[i].y1-rec[i].y2);
    }
    for(ll i=1;i<n;i++){
        for(ll j=i+1;j<=n;j++){
            ll x1=max(rec[i].x1,rec[j].x1),y1=min(rec[i].y1,rec[j].y1);
            ll x2=min(rec[i].x2,rec[j].x2),y2=max(rec[i].y2,rec[j].y2);
            if((x2-x1)*(y1-y2)>0){
                cut+=(x2-x1)*(y1-y2);
                rec[i].x2=x1;
                rec[i].y2=y2;
            }
        }
    }
    cout<<sum-cut<<"\n";
    return 0;
}