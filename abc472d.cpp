#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<pair<ll,ll>,ll>;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll h,w,k,ifs[500010][2],ans;//0->h,1->w
string s[500010];
queue<pr> q;
vector<ll> vis[500010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>h>>w>>k;
    for(ll i=1;i<=h;i++){
        vis[i].push_back(0);
        for(ll j=1;j<=w;j++){
            vis[i].push_back(0);
        }
    }
    for(ll i=1;i<=h;i++){
        cin>>s[i];
        for(ll j=1;j<=w;j++){
            if(s[i][j-1]=='#')ifs[i][0]=1,ifs[j][1]=1;
        }
    }
    for(ll i=1;i<=h;i++){
        for(ll j=1;j<=w;j++){
            if(ifs[i][0]==0&&ifs[j][1]==0)q.push({{i,j},k});
        }
    }
    while(!q.empty()){
        pr now=q.front();
        ll x=now.first.first,y=now.first.second,las=now.second;
        q.pop();
        if(x<1||x>h||y<1||y>w||s[x][y-1]=='#'||vis[x][y])continue;
        vis[x][y]=1;
        ans++;
        if(las==0)continue;
        q.push({{x-1,y},las-1});
        q.push({{x+1,y},las-1});
        q.push({{x,y-1},las-1});
        q.push({{x,y+1},las-1});
    }
    cout<<ans;
    return 0;
}