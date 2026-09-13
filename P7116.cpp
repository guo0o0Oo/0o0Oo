#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,ll>;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll MOD=1e9+7;
ll n,k,w[20],p[20],mx[20],mn[20],ans[20][1000010][2],hest[20],res;
vector<ll> op[20];
ll fd(ll num,ll up[]){
    ll l=1,r=hest[num],l1,r1;
    while(l<r){
        ll mid=(l+r+1)>>1;
        if(ans[num][mid][1]>up[1]||(ans[num][mid][1]==up[1]&&ans[num][mid][0]>up[0]))r=mid-1;
        else l=mid;
    }
    l1=l;
    l=hest[num];r=w[num];
    while(l<r){
        ll mid=(l+r)>>1;
        if(ans[num][mid][1]>up[1]||(ans[num][mid][1]==up[1]&&ans[num][mid][0]>up[0]))l=mid+1;
        else r=mid;
    }
    r1=r;
    return l1+(w[num]-r1+1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(ll i=1;i<=k;i++)cin>>w[i];
    for(ll i=1;i<=k;i++)
        for(ll j=1;j<=w[i];j++)ans[i][j][0]=sup;
    for(ll i=1;i<=n;i++){
        ll a,b;
        cin>>a>>b;
        op[a].push_back(i*b);
        p[a]+=b;
        if(mx[a]<p[a]){
            mx[a]=p[a];
            if(w[a]+1-p[a]>0&&ans[a][w[a]+1-p[a]][0]==sup)ans[a][w[a]+1-p[a]][0]=i;
        }
        if(mn[a]>p[a]){
            mn[a]=p[a];
            if(-1*p[a]<=w[a]&&ans[a][-1*p[a]][0]==sup)ans[a][-1*p[a]][0]=i;
        }
    }
    ll flag=1;
    for(ll i=1;i<=k;i++){
        if(p[i]!=0||mx[i]-mn[i]+1>w[i]){flag=0;break;}
    }
    if(flag){
        cout<<-1<<"\n";
        return 0;
    }
    for(ll i=1;i<=k;i++){
        if(p[i]>0){
            hest[i]=-mn[i]+1;
            for(ll j=w[i]-mx[i];j>=1&&ans[i][j][0]==sup;j--){
                ans[i][j][0]=ans[i][j+p[i]][0];
                ans[i][j][1]=ans[i][j+p[i]][1]+1;
            }
        }
        if(p[i]<0){
            hest[i]=w[i]-mx[i];
            for(ll j=-mn[i]+1;j<=w[i]&&ans[i][j][0]==sup;j++){
                ans[i][j][0]=ans[i][j+p[i]][0];
                ans[i][j][1]=ans[i][j+p[i]][1]+1;
            }
        }
        if(p[i]==0){
            hest[i]=-mn[i]+1;
        }
    }
    for(ll i=1;i<=k;i++){
        for(ll j=1;j<=w[i];j++){
            ll s=ans[i][j][0]+ans[i][j][1]*n%MOD;
            s%=MOD;
            for(ll kk=1;kk<=k;kk++){
                if(kk!=i){
                    s*=fd(kk,ans[i][j]);
                    s%=MOD;
                }
            }
            res+=s;
            res%=MOD;
        }
    }
    cout<<res<<"\n";
    return 0;
}