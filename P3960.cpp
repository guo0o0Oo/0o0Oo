#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=3e5+10;
ll n,m,q;
ll pos[N][2],ans[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    for(ll i=1;i<=q;i++){
        ll x,y;
        cin>>x>>y;
        pos[i][0]=x;pos[i][1]=y;
        ll res=inf;
        for(ll j=i-1;j>=1;j--){
            if(x==n&&y==m){res=ans[j];break;}
            else if(x>=pos[j][0]&&y==m)x++;
            else if(x==pos[j][0]&&y>=pos[j][1])y++;
        }
        if(res==inf)res=m*(x-1)+y;
        ans[i]=res;
        cout<<res<<"\n";
    }
    return 0;
}