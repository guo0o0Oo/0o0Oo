#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll x[3];
    cin>>x[0]>>x[1]>>x[2];
    sort(x,x+3);
    ll a=x[0],b=x[1],c=x[2];
    if(a+b<=c){
        cout<<"Not triangle\n";
        return 0;
    }
    if(c*c==a*a+b*b){
        cout<<"Right triangle\n";
    }
    if(c*c<a*a+b*b){
        cout<<"Acute triangle\n";
    }
    if(c*c>a*a+b*b){
        cout<<"Obtuse triangle\n";
    }
    if(a==b||b==c){
        cout<<"Isosceles triangle\n";
    }
    if(a==b&&b==c){
        cout<<"Equilateral triangle\n";
    }
    return 0;
}