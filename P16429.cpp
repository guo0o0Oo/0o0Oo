#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define F(i,a,b) for(ll i=a;i<=b;i++)
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n;
string p,q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    F(i,1,n){
        cin>>p>>q;
        if(p.size()!=7||(p[3]=='0'&&p[4]=='0'&&p[5]=='0'&&p[6]=='0')){
            cout<<"Wrong Name\n";
            continue;
        }
        if(q.size()<6){
            cout<<"Wrong Password\n";
            continue;
        }
        ll s=0,l=0,f=0;
        F(j,0,q.size()){
            if(q[j]>='0'&&q[j]<='9')f=1;
            if(q[j]>='a'&&q[j]<='z')s=1;
            if(q[j]>='A'&&q[j]<='Z')l=1;
        }
        if(s&&l&&f){
            cout<<"Accept\n";
        }
        else{
            cout<<"Wrong Password\n";
        }
    }
    return 0;
}