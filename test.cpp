#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) x&-x

int x,y;
void solve(){
    cin>>x>>y;
    while(x){
        int p=lowbit(x);
        x-=p;
        if(!x||!(y&p)){
            y|=p;
            continue;
        }
        int pp=lowbit(x);
        if(!(y&pp)&&((y+p)&pp)) y+=p;
    }
    cout<<y<<endl;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;while(T--) solve();
	return 0;
}