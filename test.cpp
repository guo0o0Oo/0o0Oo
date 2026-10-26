#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool ifpr(ll x){
    for(ll i=2;i<=sqrt(x);i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
	for(ll i=2;i<=31;i++){
        if(ifpr(i))cout<<i<<",";
    }
}