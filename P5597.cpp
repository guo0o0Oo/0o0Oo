#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=2e3+10;
struct node{
    ll l,r;
}t[N],new_t[N];
ll cnt,new_cnt,ans=sup;
ll read(){
    ll op=getchar()-'0',num=++cnt;
    if(op&1)t[num].l=read();
    if(op&2)t[num].r=read();
    return num;
}
void dfs(ll u,ll v,ll pos1,ll pos2){//u->newtree,v->oldtree
    if(v==pos1||u==pos2)pos2=u,u=1;
    if(t[v].l){
        if(new_t[u].l==0)new_t[u].l=++new_cnt;
        dfs(new_t[u].l,t[v].l,pos1,pos2);
    }
    if(t[v].r){
        if(new_t[u].r==0)new_t[u].r=++new_cnt;
        dfs(new_t[u].r,t[v].r,pos1,pos2);
    }
}
void solve(ll node,ll dep){
    new_cnt=1;
    memset(new_t,0,sizeof(new_t));
    dfs(1,1,node,sup);
    ans=min(ans,2*(new_cnt-1)-dep);
    //cout<<node<<" "<<new_cnt<<" "<<dep<<"\n";
    if(t[node].l)solve(t[node].l,dep+1);
    if(t[node].r)solve(t[node].r,dep+1);
}
int main(){
    read();
    if(cnt==1){
        cout<<"1"<<"\n";
        return 0;
    }
    if(t[1].l)solve(t[1].l,1);
    if(t[1].r)solve(t[1].r,1);
    cout<<ans<<"\n";
    return 0;
}