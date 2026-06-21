#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
struct cell{
    ll r,c,num;
    const bool operator<(const cell& a)const{
        if(c==a.c){
            return r>a.r;
        }
        return c<a.c;
    }
}pos[N];
ll n,m,k;
bool ifc[N];
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        for(int i=1;i<=k;i++){
            cin>>pos[i].r>>pos[i].c;
            pos[i].num=i;
        }
        sort(pos+1,pos+k+1);
        ll h=1,ans=0,l=0;
        for(int i=1;i<=k;i++){
            if(h<=pos[i].r){
                ifc[pos[i].num]=1;
                ans+=(pos[i].c-l)*(n-h+1)-pos[i].r+h-1;
                h=pos[i].r+1;
                l=pos[i].c;
            }
            else ifc[pos[i].num]=0;
        }
        ans+=(m-l)*(n-h+1);
        cout<<ans<<"\n";
        for(int i=1;i<=k;i++){
            cout<<ifc[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}