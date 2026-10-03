#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,ll>;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,k,a[1000010],b[1000010],now;
queue<pr> q;//second:1->a,2->b
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    q.push({0,1});
    while(!q.empty()){
        ll i=q.front().first,tpe=q.front().second;
        if(tpe==1){
            if(a[i]==a[(i+2)%n]){
                
            }
        }
        else{}
    }
    return 0;
}