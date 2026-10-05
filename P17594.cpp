#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define lowbit(x) ((x)&-(x))
const ll inf=0x3f3f3f3f3f3f3f3f;
ll x,y;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;	cin>>T;
    while(T--){
        cin>>x>>y;
        while(x){
            if(x==lowbit(x)||(y&lowbit(x))==0){
                y|=lowbit(x);
                x-=lowbit(x);
                continue;
            }
            if((lowbit(x-lowbit(x))&y)==0&&((y+lowbit(x))&lowbit(x-lowbit(x))))y+=lowbit(x);
            else y|=lowbit(x);
            x-=lowbit(x);
        }
        cout<<y<<"\n";
    }
    return 0;
}