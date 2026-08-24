#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,m,a[100][500],cnt;
queue<pair<ll,ll> > q;
void fd(ll &x,ll &y,ll col,ll dep){
    for(ll i=1;i<=dep;i++){
        for(ll j=1;j<=n;j++){
            if(a[i][j]==col){
                x=i;y=j;
                return;
            }
        }
    }
}
void swp(ll x,ll y,ll a,ll b){
    if(y==b){
        ll dat=1+(y%n);
        for(ll i=1;i<=a-1;i++)cnt++,q.push({y,n+1});
        cnt++,q.push({dat,n+1});
        cnt++,q.push({y,dat});
        for(ll i=a+1;i<=x;i++)cnt++,q.push({y,n+1});
        cnt++,q.push({dat,y});
        cnt++,q.push({n+1,dat});
        for(ll i=1;i<=x-a-1;i++)cnt++,q.push({n+1,y});
        cnt++,q.push({dat,y});
        cnt++,q.push({n+1,dat});
        for(ll i=1;i<=a-1;i++)cnt++,q.push({n+1,y});
        return;
    }
    for(ll i=1;i<=x;i++)cnt++,q.push({y,n+1});
    for(ll i=1;i<=a-1;i++)cnt++,q.push({b,y});
    cnt++,q.push({b,y});
    cnt++,q.push({n+1,b});
    cnt++,q.push({y,n+1});
    for(ll i=1;i<=a-1;i++)cnt++,q.push({y,b});
    for(ll i=1;i<=x;i++)cnt++,q.push({n+1,y});
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        for(ll j=m;j>=1;j--)cin>>a[j][i];
    for(ll i=m;i>=1;i--){
        for(ll j=1;j<=n;j++){
            if(a[i][j]!=j){
                ll x,y;
                fd(x,y,j,i);
                swp(i,j,x,y);
                swap(a[i][j],a[x][y]);
            }
        }
    }
    cout<<cnt<<"\n";
    while(!q.empty()){
        cout<<q.front().first<<" "<<q.front().second<<"\n";
        q.pop();
    }
    return 0;
}