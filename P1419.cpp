#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e5+10;
const double eps=1e-4;
ll n,s,t;
double a[N],sum[N];
deque<ll> q;
int main(){
    cin>>n>>s>>t;
    for(ll i=1;i<=n;i++)cin>>a[i];
    double l=-1e4,r=1e4;
    while(r-l>eps){
        //cerr<<l<<" "<<r<<"\n";
        double mid=(l+r)/2.0;
        for(ll i=1;i<=n;i++)sum[i]=sum[i-1]+a[i]-mid;
        while(!q.empty())q.pop_front();
        double ans=inf;
        for(ll i=s;i<=n;i++){
            while(!q.empty()&&q.front()<i-t)q.pop_front();
            while(!q.empty()&&sum[q.back()]>=sum[i-s])q.pop_back();
            q.push_back(i-s);
            ans=max(ans,(sum[i]-sum[q.front()]));
        }
        if(ans>0)l=mid;
        else r=mid;
    }
    printf("%.3f",l);
    return 0;
}