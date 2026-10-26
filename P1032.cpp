#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,string>;
const ll inf=0x3f3f3f3f3f3f3f3f;
string A,B,a[10],b[10];
ll cnt=0;
queue<pr> q;
map<string,bool> c;
ll bfs(){
    q.push({0,A});
    c[A]=1;
    while(!q.empty()){
        pr t=q.front();q.pop();
        ll dep=t.first;
        string ts=t.second;
        if(ts==B)return dep;
        if(dep==10)continue;
        for(ll i=1;i<cnt;i++){
            size_t p=ts.find(a[i]);
            while(p!=string::npos){
                string ns=ts;
                ns.replace(p,a[i].size(),b[i]);
                if(c.find(ns)==c.end()){
                    q.push({dep+1,ns});
                    c[ns]=1;
                }
                p=ts.find(a[i],p+1);
            }
        }
    }
    return inf;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>A>>B;
    while(cin>>a[++cnt]){
        cin>>b[cnt];
    }
    ll ans=bfs();
    if(ans==inf)cout<<"NO ANSWER!"<<"\n";
    else cout<<ans<<"\n";
    return 0;
}