#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;	cin>>t;
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;
        if(n==1){
            if(x==y)cout<<"YES\n";
            else cout<<"NO\n";
        }
        else{
            if(x>=0&&y<=0)cout<<"YES\n";
            else if(x==0||y==0)cout<<"YES\n";
            else if(x>0&&y>0){
                if(x/n>=y)cout<<"YES\n";
                else cout<<"NO\n";
            }
            else if(x<0&&y<0){
                if(y/n<=x)cout<<"YES\n";
                else cout<<"NO\n";
            }
        }
    }
    return 0;
}