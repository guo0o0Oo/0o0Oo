#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
double n,l,r,a[20];
double f(double x){
    double res=0;
    for(ll i=1;i<=n+1;i++)res*=x,res+=a[i];
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>l>>r;
    for(ll i=1;i<=n+1;i++)cin>>a[i];
    while(r-l>eps){
        double k=(r-l)/3;
        double mid1=l+k,mid2=r-k;
        if(f(mid1)<f(mid2))l=mid1;
        else r=mid2;
    }
    printf("%.5f",l);
    return 0;
}