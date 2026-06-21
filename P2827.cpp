#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,m,q,u,v,t,a[100010],add;
queue<ll> q1,q2,q3;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>q>>u>>v>>t;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=n;i>=1;i--)q1.push(a[i]);
    for(ll i=1;i<=m;i++){
        ll len=inf,pos;
        if(!q1.empty()&&q1.front()>len)len=q1.front(),pos=1;
        if(!q2.empty()&&q2.front()>len)len=q2.front(),pos=2;
        if(!q3.empty()&&q3.front()>len)len=q3.front(),pos=3;
        if(pos==1)q1.pop();
        if(pos==2)q2.pop();
        if(pos==3)q3.pop();
        len+=add;
        add+=q;
        q2.push(len*u/v-add);
        q3.push(len-len*u/v-add);
        if(i%t==0)cout<<len<<" ";
    }
    cout<<"\n";
    for(ll i=1;i<=n+m;i++){
        ll len=inf,pos;
        if(!q1.empty()&&q1.front()>len)len=q1.front(),pos=1;
        if(!q2.empty()&&q2.front()>len)len=q2.front(),pos=2;
        if(!q3.empty()&&q3.front()>len)len=q3.front(),pos=3;
        if(pos==1)q1.pop();
        if(pos==2)q2.pop();
        if(pos==3)q3.pop();
        len+=add;
        if(i%t==0)cout<<len<<" ";
    }
    return 0;
}