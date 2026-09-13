#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;

ll n,t,a,b,x,y,lastans,cnt,ans,l[1000010],fa[1000010],st[500010][21],lg2[1000010];
pair<ll,ll> s[1000010]; // first->sco, second->x
pair<double,ll> res[1000010]; // first->score/x (double), second->x

void init(){
    for(ll i=2;i<=1000000;i++) lg2[i]=lg2[i/2]+1;
}

ll find(ll x){
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}

void unite(ll x,ll y){
    ll fx=find(x),fy=find(y);
    if(fx!=fy){
        cnt--;
        ans+=l[fx]*l[fy]*2;
        l[fy]+=l[fx];
        fa[fx]=fy;
    }
}

// 比较函数：优先选分数大的，分数相同选 x 大的
pair<double,ll> choose(pair<double,ll> u,pair<double,ll> v){
    if(u.first > v.first) return u;
    else if(u.first < v.first) return v;
    else if(u.second < v.second) return v;
    else return u;
}

ll ask(ll l,ll r){
    ll len=(r-l+1);
    if(choose(res[st[l][lg2[len]]],res[st[r-(1<<lg2[len])+1][lg2[len]]])==res[st[l][lg2[len]]])
        return st[l][lg2[len]];
    else 
        return st[r-(1<<lg2[len])+1][lg2[len]];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    init();
    
    cin>>n>>t;
    for(ll i=1;i<=n;i++){
        cin>>s[i].first;
        s[i].second=i;
    }
    
    sort(s+1,s+n+1);
    
    for(ll i=1;i<=n;i++){
        fa[s[i].second]=s[i].second;
        cnt++;
        l[s[i].second]=1;
        ans++;
        
        if(s[i].second>1 && fa[s[i].second-1]) unite(s[i].second-1,s[i].second);
        if(s[i].second<n && fa[s[i].second+1]) unite(s[i].second,s[i].second+1);
        
        if(i<n && s[i].first==s[i+1].first) continue;
        
        // 存入 double 类型的分数
        res[cnt]=choose(res[cnt], {1.0*ans/s[i].first, s[i].first});
    }
    
    for(ll i=1;i<=500010;i++) st[i][0]=i;
    for(ll k=1;k<=20;k++){
        for(ll i=1;i+(1<<k)-1<=500010;i++){
            if(choose(res[st[i][k-1]],res[st[i+(1<<(k-1))][k-1]])==res[st[i][k-1]])
                st[i][k]=st[i][k-1];
            else 
                st[i][k]=st[i+(1<<(k-1))][k-1];
        }
    }
    
    while(t--){
        cin>>a>>b>>x>>y;
        ll l,r;
        // 修正：正确的强制在线解密公式
        l = (a * lastans + x - 1) % n + 1;
        r = (b * lastans + y - 1) % n + 1;
        if (l > r) swap(l, r);
        
        ll p=ask(l,r);
        
        if(res[p].first==0){
            cout<<-1<<" "<<-1<<"\n";
            cout<<l<<" "<<r<<" "<<lastans<<"\n";
            lastans=1;
        }
        else{
            // 还原原始得分并输出
            ll original_score = (ll)(res[p].first * res[p].second + 0.5);
            cout<<original_score<<" "<<res[p].second<<"\n";
            cout<<l<<" "<<r<<" "<<lastans<<"\n";
            lastans = original_score * res[p].second % n;
        }
        
    }
    return 0;
}