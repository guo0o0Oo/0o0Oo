#include<bits/stdc++.h>
using namespace std;
using pr=pair<int,int>;
struct duan{
    int l,r;
    int num;
}a[200010];
int l,r,n,k;
bool ifc[200010];
bool cmp(const duan a,const duan  b){
    if(a.r==b.r)return a.l>b.l;
    return a.r<b.r;
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>l>>r;
        a[i].r=r;
        a[i].l=l;
        a[i].num=i;
    }
    sort(a+1,a+n+1,cmp);
    int sum=0;
    while(k--){
        int last=0;
        for(int i=1;i<=n;i++){
            if(!ifc[a[i].num]){
                if(last<a[i].l){
                    ifc[a[i].num]=1;
                    last=a[i].r;
                    sum++;
                }
            }
        }
    }
    cout<<n-sum<<"\n";
    for(int i=1;i<=n;i++){
        if(!ifc[i]){
            cout<<i<<" ";
        }
    }
}