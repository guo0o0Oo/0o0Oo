#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
string f;
char x;
ll a,b,pos,op=1;
void get(){
    ll n=0,neg=1;
    if(f[pos]=='-')neg=-1,pos++;
    if(f[pos]=='+')pos++;
    while(f[pos]>='0'&&f[pos]<='9')n=n*10+f[pos]-'0',pos++;
    if(pos<f.size()&&f[pos]>='a'&&f[pos]<='z'){
        if(n==0)n=1;
        x=f[pos];
        a+=n*op*neg;
        pos++;
    }
    else{
        b+=n*op*neg;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>f;
    while(pos!=f.size()){
        get();
        if(f[pos]=='='){
            op=-1;
            pos++;
        }
    }
    double p=a,q=b;
    printf("%c=%.3f",x,-(q/p));
    return 0;
}