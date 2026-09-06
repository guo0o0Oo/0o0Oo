#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,ll>;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=600;
ll h[N][N],x,y,z,n,m,p,a,b,c,ans;
queue<pr> q;
void bfs(){
    q.push()
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>p;
    char ch;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            h[i][j]=inf;
        }
    }
    for(ll k=1;k<=p;k++)
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>ch;
            if(ch=='R'){x=i;y=j;z=k;}
            if(ch=='T'){a=i;b=j;c=k;}
            if(ch=='*')h[i][j]=k;
        }
    }

    return 0;
}