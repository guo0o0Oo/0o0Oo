#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
priority_queue<ll,vector<ll>,greater<ll> > q;
ll n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll op,a;
    cin>>n;
    while(n--){
        cin>>op;
        if(op==1){
            cin>>a;
            q.push(a);
        }
        else if(op==2)cout<<q.top()<<"\n";
        else q.pop();
    }
    return 0;
}