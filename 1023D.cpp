#include<bits/stdc++.h>
using namespace std;
int a[200010],n,q,b[200010];
bool check(){
    for(int i=1;i<=n;i++){
        if(b[i]==0){
            b[i]=b[i-1];
        }
    }
    for(int i=n;i>=1;i--){
        if(b[i]==0){
            b[i]=b[i+1];
        }
    }
    bool up=1;
    for(int i=2;i<=n;i++){
        if(b[i]==0)continue;
        if(b[i]>b[i-1]){
            if(!up){
                cout<<"NO"<<"\n";
                return 0;
            }
            continue;
        }
        else if(b[i]<b[i-1]){
            if(up){
                up=0;
                continue;
            }
        }
    }
    return 1;
}
int main(){
    cin>>n>>q;
    int cnt0=0,has=0,maxa=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
        maxa=max(maxa,a[i]);
        if(a[i]==0)cnt0++;
        if(a[i]==q)has=1;
    }
    if(cnt0==n){
        cout<<"YES"<<"\n";
        for(int i=1;i<=n;i++){
            cout<<q<<" ";
        }
        return 0;
    }
    if(has==0&&cnt0==0){
        cout<<"NO"<<"\n";
        return 0;
    }
    if(!check()){
        return 0;
    }
    if(has==0){
        bool flag=1;
        for(int i=1;i<=n;i++){
            if(a[i]==maxa){
                if(a[i-1]==0){
                    a[i-1]=q;
                    flag=0;
                    break;
                }
                if(a[i+1]==0){
                    a[i+1]=q;
                    flag=0;
                    break;
                }
            }
        }
        if(flag){
            cout<<"NO"<<"\n";
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            a[i]=a[i-1];
        }
    }
    for(int i=n;i>=1;i--){
        if(a[i]==0){
            a[i]=a[i+1];
        }
    }
    cout<<"YES"<<"\n";
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
}