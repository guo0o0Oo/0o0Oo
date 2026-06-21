#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[5010],n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
    }
    
}