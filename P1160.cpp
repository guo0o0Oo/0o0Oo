#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e5+10;
list<ll> stu;
list<ll> ::iterator pos[N];
bool exi[N];
ll n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll k,q;
    cin>>n;
    stu.push_back(1);
    pos[1]=stu.begin();
    for(ll i=2;i<=n;i++){
        cin>>k>>q;
        if(q==0){
            stu.insert(pos[k],i);
            pos[i]=pos[k];
            pos[i]--;
        }
        else{
            stu.insert(++pos[k],i);
            pos[i]=--pos[k];
            pos[k]--;
        }
    }
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>k;
        if(!exi[k])stu.erase(pos[k]);
        exi[k]=1;
    }
    for(auto i:stu)cout<<i<<" ";
    return 0;
}