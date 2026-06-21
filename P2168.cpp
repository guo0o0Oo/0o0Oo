#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e5+10;
ll n,k;
struct ch{
    ll size,h;
    bool operator <(const ch &a)const{
        if(size==a.size)return h>a.h;
        return size>a.size;
    }
};
priority_queue<ch> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    ch a;
    a.h=0;
    for(ll i=1;i<=n;i++){
        cin>>a.size;
        q.push(a);
    }
    ll ans=0;
    if(n<k){
        while(!q.empty()){
            ans+=q.top().size;
            q.pop();
        }
        cout<<ans<<"\n";
        if(n==1)cout<<0<<"\n";
        else cout<<1<<"\n";
        return 0;
    }
    while((n-1)%(k-1)){
        q.push({0,0});
        n++;
    }
    while(q.size()>1){
        ch now={0,0};
        for(ll i=1;i<=k;i++){
            if(q.empty())break;
            now.size+=q.top().size;
            now.h=max(now.h,q.top().h+1);
            q.pop();
        }
        ans+=now.size;
        q.push(now);
    }
    cout<<ans<<"\n";
    cout<<q.top().h<<"\n";
    return 0;
}