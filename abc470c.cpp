#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,q,a[500010],ans;
queue<ll> dat,pq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    while(q--){
        ll op,x;
        cin>>op;
        if(op==1){
            cin>>x;
            if(a[x]){
                ans^=a[x];
                a[x]++;
                ans^=a[x];
            }
            else{
                a[x]=1;
                pq.push(x);
                ans^=1;
            }
        }
        else{
            while(!pq.empty()){
                ll p=pq.front();
                if(a[p]==1){
                    a[p]--;
                    ans^=1;
                    pq.pop();
                }
                else{
                    ans^=a[p];
                    a[p]--;
                    ans^=a[p];
                    dat.push(p);
                    pq.pop();
                }
            }
            while(!dat.empty()){
                pq.push(dat.front());
                dat.pop();
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}