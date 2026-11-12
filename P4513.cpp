#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll N=5e5+10;
ll n,m,a[N],tree[N<<2][4];//0->left,1->right,2->mid,3->all
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void pushup(ll p){
    tree[p][0]=max(tree[ls(p)][0],tree[ls(p)][3]+tree[rs(p)][0]);
    tree[p][1]=max(tree[rs(p)][1],tree[rs(p)][3]+tree[ls(p)][1]);
    tree[p][2]=max({tree[ls(p)][2],tree[rs(p)][2],tree[ls(p)][1]+tree[rs(p)][0]});
    tree[p][3]=tree[ls(p)][3]+tree[rs(p)][3];
}
void build(ll p,ll pl,ll pr){
    if(pl==pr){
        for(ll i=0;i<4;i++)tree[p][i]=a[pl];
        return;
    }
    ll mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    pushup(p);
}
void update(ll p,ll pl,ll pr,ll P,ll S){
    if(P==pl&&P==pr){
        a[P]=S;
        for(ll i=0;i<4;i++)tree[p][i]=a[P];
        return;
    }
    ll mid=(pl+pr)>>1;
    if(P<=mid)update(ls(p),pl,mid,P,S);
    else update(rs(p),mid+1,pr,P,S);
    pushup(p);
}
vector<ll> query(ll p,ll pl,ll pr,ll L,ll R){
    if(L<=pl&&pr<=R)return {tree[p][0],tree[p][1],tree[p][2],tree[p][3]};
    if(pr<L||R<pl)return {-inf,-inf,-inf,-inf};
    vector<ll> res(4),gtl,gtr;
    ll mid=(pl+pr)>>1;
    gtl=query(ls(p),pl,mid,L,R);
    gtr=query(rs(p),mid+1,pr,L,R);
    if(gtl[0]==-inf)return gtr;
    if(gtr[0]==-inf)return gtl;
    res[0]=max(gtl[0],gtl[3]+gtr[0]);
    res[1]=max(gtr[1],gtr[3]+gtl[1]);
    res[2]=max({gtl[2],gtr[2],gtl[1]+gtr[0]});
    res[3]=gtl[3]+gtr[3];
    res[0]=max(gtl[0],gtl[3]+gtr[0]);
    res[1]=max(gtr[1],gtr[3]+gtl[1]);
    res[2]=max({gtl[2],gtr[2],gtl[1]+gtr[0]});
    res[3]=gtl[3]+gtr[3];
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    for(ll i=1;i<=m;i++){
        ll k,a,b;cin>>k>>a>>b;
        if(k==1){
            if(a>b)swap(a,b);
            vector<ll> res=query(1,1,n,a,b);
            cout<<max({res[0],res[1],res[2],res[3]})<<"\n";
        }
        else{
            update(1,1,n,a,b);
        }
    }
    return 0;
}