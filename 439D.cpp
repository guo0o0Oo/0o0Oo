#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100010],n,m;
bool alla=0,allb=0;
int equal(bool op){
    if(op){
        for(int i=2;i<=n;i++){
            if(a[i]!=0){
                return i-1;
            }
        }
        alla=1;
        return n;
    }
    else{
        for(int i=m;i>=1;i--){
            if(b[i]!=0){
                if(i==1)allb=1;
                return m-i+1;
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    int mina=a[1],maxb=b[m];
    if(n==1){
        cout<<min(0,maxb-mina)<<"\n";
        return 0;
    }
    if(m==1){
        cout<<min(0,maxb-mina)<<"\n";
        return 0;
    }
    for(int i=n;i>1;i--){
        a[i]-=a[i-1];
    }
    for(int i=m;i>1;i--){
        b[i]-=b[i-1];
    }
    int sizea=equal(1),sizeb=equal(0);
    int ans=0;
    while(mina<maxb){
        if(sizea<sizeb){
            if(alla){
                ans+=sizea;
                mina++;
                continue;
            }
            ans+=sizea;
            a[1]++;
            a[sizea+1]--;
            if(a[sizea+1]==0){
                for(int i=sizea+1;i<=n;i++){
                    if(a[i]==0)sizea++;
                    else break;
                }
                if(sizea==n)alla=1;
            }
            mina++;
        }
        else{
            b[m-sizeb+1]--;
            ans+=sizeb;
            sizeb=equal(0);
            maxb--;
        }
    }
    cout<<ans<<"\n";
    return 0;
}