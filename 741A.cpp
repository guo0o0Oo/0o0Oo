#include<bits/stdc++.h>
using namespace std;
long long n,a[220],b[220],cnt[220];
bool dfs(){
    bool flag=1;
    for(int i=1;i<=n;i++){
        if(b[b[i]]!=i){
            flag=0;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        b[i]=a[b[i]];
    }
    return flag;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
        cnt[a[i]]++;
    }
    for(int i=1;i<=n;i++)
        if(cnt[i]==0){
            cout<<-1<<"\n";
            return 0;
        }
    long long res=1;
    for(int i=1;i<=n;i++){
        long long cnt=1;
        while(b[i]!=i){
            b[i]=a[b[i]];
            cnt++;
        }
        if(cnt%2==0)cnt/=2;
        res=res*cnt/__gcd(res,cnt);
    }
    cout<<res;
    return 0;
}