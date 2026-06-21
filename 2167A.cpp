#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a==b&&c==d&&a==c){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
}