#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    double s,k=2;
    ll cnt=0;
    cin>>s;
    while(s>0){
        s-=k;
        k*=0.98;
        cnt++;
    }
    cout<<cnt<<"\n";
    return 0;
}