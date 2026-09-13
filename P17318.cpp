#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,k;
    cin>>n>>k;
    if(n==0||(k==1 && n%2==0)){
        cout<<"Austin";
    }
    else{
        cout<<"Adrien";
    }
    return 0;
}