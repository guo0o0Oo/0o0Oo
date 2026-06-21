#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int t;
    cin>>t;
    while(t--){
        int s;
        int a,b;
        cin>>a>>b>>s;
        for(int i=0;;i++){
            if(a>s||b>s){
                cout<<i<<"\n";
                break;
            }
            if(a>b){
                b+=a;
            }
            else{
                a+=b;
            }
        }
    }

    return 0;
}