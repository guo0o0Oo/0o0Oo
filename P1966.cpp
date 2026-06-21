#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+10;
const int MOD=1e8-3;
ll tmp[N],ra[N],c[N],n,ans;
pair<ll,ll> a[N],b[N];
void f(int l,int r){
    if(l==r){
        return ;
    }
    int mid=(l+r)>>1;
    f(l,mid);
    f(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r){
        if(c[i]<=c[j]){
            tmp[k++]=c[i++];
        }
        else{
            tmp[k++]=c[j++];
            ans=(ans+mid-i+1)%MOD;
        }
    }
    while(i<=mid)tmp[k++]=c[i++];
    while(j<=r)tmp[k++]=c[j++];
    for(int i=l;i<=r;i++){
        c[i]=tmp[i];
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i].first;
        b[i].second=i;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        ra[a[i].second]=i;
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
        c[b[ra[i]].second]=i;
    }
    f(1,n);
    cout<<ans;
    return 0;
}