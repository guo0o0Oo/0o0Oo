#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll tmp[N],n,ans;
struct pr{
    int first,second;
    const bool operator<(const pr& a){
        if(first==a.first){
            return second<a.second;
        }
        return first<a.first;
    }
}a[N];
void f(int l,int r){
    if(l==r){
        return ;
    }
    int mid=(l+r)>>1;
    f(l,mid);
    f(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r){
        if(a[i].second<=a[j].second){
            tmp[k++]=a[i++].second;
        }
        else{
            tmp[k++]=a[j++].second;
            ans=(ans+mid-i+1);
        }
    }
    while(i<=mid)tmp[k++]=a[i++].second;
    while(j<=r)tmp[k++]=a[j++].second;
    for(int i=l;i<=r;i++){
        a[i].second=tmp[i];
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].second;
    }
    f(1,n);
    cout<<ans;
    return 0;
}