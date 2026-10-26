#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
const ll N=2e6+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,a[N],last[100],lastk[100],ans;
deque<ll> come[N],comek[100];
void init(){
    for(ll k=0;k<=30;k++){
        ll cnt=0,now=0;
        now+=n*(n+1)/2;
        for(ll i=1;i<=n;i++){
            if((a[i]&(1<<k))==0){
                cnt++;
            }
            else{
                if(cnt){
                    now-=cnt*(cnt+1)/2;
                    cnt=0;
                }
            }
        }
        if(cnt){
            now-=cnt*(cnt+1)/2;
            cnt=0;
        }
        now*=(1<<k);
        ans+=now;
    }
    for(ll i=1;i<=n;i++){
        come[a[i]].push_back(i);
        for(ll k=0;k<=21;k++)if(a[i]&(1<<k))comek[k].push_back(i);
    }
    for(ll k=0;k<=21;k++){
        for(ll i=1;i<(1<<k);i++){
            if(come[i].empty()){
                last[k]=inf;
                break;
            }
            last[k]=max(last[k],come[i][0]);
        }
        if(comek[k].empty()){
            lastk[k]=inf;
            break;
        }
        lastk[k]=max(comek[k][0],lastk[k]);
    }
}
void solve(){
    for(ll i=1;i<=n;i++){
        for(ll k=0;k<=21;k++){
            ll l=last[k],r=lastk[k];
            ans+=max(0ull,r-l)*(1<<k);
        }
        come[a[i]].pop_front();
        if(come[a[i]].empty()){
            
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    init();
    cout<<ans<<"\n";
}