#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
double a,b,c,d;
double f(double x){return a*x*x*x+b*x*x+c*x+d;}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>a>>b>>c>>d;
    for(double i=-101.00;i<101.00;i+=0.01){
        if(f(i-0.001)*f(i+0.001)<0)printf("%.2f ",i);
    }
    return 0;
}