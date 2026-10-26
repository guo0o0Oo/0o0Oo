#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,pos[20],col[20],cut[40],add[40],sum;
void dfs(ll dep){
    if(dep==n+1){
        sum++;
        if(sum>3)return;
        for(ll i=1;i<=n;i++){
            cout<<pos[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(ll i=1;i<=n;i++){
        ll nx=dep,ny=i;
        if(!col[ny]&&!cut[nx-ny+20]&&!add[nx+ny]){
            col[ny]=1;cut[nx-ny+20]=1;add[nx+ny]=1;
            pos[dep]=i;
            dfs(dep+1);
            col[ny]=0;cut[nx-ny+20]=0;add[nx+ny]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    dfs(1);
    cout<<sum<<"\n";
    return 0;
}