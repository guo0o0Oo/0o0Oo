#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int fa[1010],n,m;
struct send{
    ll a,b;
    bool op;
    send operator*(const send& other){
        ll newa=a*other.a;
        ll newb=b*other.b;
        ll gcdab=__gcd(abs(newa),abs(newb));
        newa/=gcdab;
        newb/=gcdab;
        return {newa,newb,op^other.op};
    }
    send operator/(const send& other){
        return (send){a,b,op}*(send){other.b,other.a,other.op};
    }
    bool operator!=(const send& other){
        return op!=other.op||a!=other.a||b!=other.b;
    }
}se[1010];
void init(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=n;i++){
        se[i]={1,1,0};
    }
}
bool ifroot(int u){
    if(u==fa[u])return 1;
    else return 0;
}
int find(int u){
    if(!ifroot(fa[u])){
        int data=fa[u];
        fa[u]=find(fa[u]);
        se[u]=se[u]*se[data];
    }
    return fa[u];
}
void unite(int u,int v,send k){
    int rootu=find(u);
    int rootv=find(v);
    send uk=se[u];
    send vk=se[v];
    send newk=(k/uk)*vk;
    fa[rootu]=rootv;
    se[rootu]=newk;
}
bool check(int u,int v,send k){
    //cout<<u<<" "<<v<<" "<<k.a<<" "<<k.b<<"\n";
    int rootu=find(u);
    int rootv=find(v);
    if(rootu==rootv){
        send uk=se[u];
        send vk=se[v];
        send newk=uk/vk;
        //cout<<newk.a<<" "<<newk.b<<"\n";
        if(newk!=k){
            return false;
        }
        else{
            return true;
        }
    }
    unite(u,v,k);
    //print();
    return true;
}
int main(){
    int t;	cin>>t;
    for(int ii=1;ii<=t;ii++){
        int u,v,x,y;
        cin>>n>>m;
        init();
        bool flag=1;
        for(int i=1;i<=m;i++){
            cin>>u>>v>>x>>y;
            bool op=(x<0)^(y<0);
            send k={abs(x),abs(y),op};
            if(!check(u,v,k)){
                cout<<"Case #"<<ii<<": No\n";
                flag=0;
                break;
            }
        }
        if(flag)cout<<"Case #"<<ii<<": Yes\n";
    }
    return 0;
}