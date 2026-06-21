#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int res=0;
        res=max(min(a,b)*min(c,d),res);
        res=max(min(a,c)*min(b,d),res);
        res=max(min(a,d)*min(c,b),res);
        cout<<res<<"\n";
    }
}