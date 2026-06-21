#include<bits/stdc++.h>
using namespace std;
long long a[3010][3010];
bool c[3010][3010];
long long sum[3010][3010];
long long n,m;
bool check(int k){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]>=k)c[i][j]=1;
            else c[i][j]=0;
        }
    }
    sum[1][1]=c[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+c[i][j];
        }
    }
    int tot=k*k;
    for(int i=k;i<=n;i++){
        for(int j=k;j<=m;j++){
            if(sum[i][j]-sum[i-k][j]-sum[i][j-k]+sum[i-k][j-k]==tot){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        int l=1,r=min(n,m);
        while(l<r){
            int mid=(l+r+1)>>1;
            if(check(mid)){
                l=mid;
            }
            else{
                r=mid-1;
            }
        }
        cout<<l<<"\n";
    }
    return 0;
}