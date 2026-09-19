#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pr=pair<ll,ll>;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll N=1e6+10;
ll n,a[N];
deque<pr> q1,q2;
void solve(){
    q1.clear();q2.clear();
    for(ll i=n;i>=1;i--)q1.push_back({a[i],i});
    ll cnt=0;
    for(ll i=n;i>=2;i--){
        pr now,mx,mn;
        if(i==2){
            if(cnt){
                cout<<i+cnt-((cnt+1)&1)<<"\n";
                return;
            }
            else{
                cout<<1<<"\n";
                return;
            }
        }
        if(!q1.empty()&&!q2.empty()){
            if(q1.front()>q2.front()){mx=q1.front();q1.pop_front();}
            else {mx=q2.front();q2.pop_front();}
            if(q1.back()<q2.back()){mn=q1.back();q1.pop_back();}
            else {mn=q2.back();q2.pop_back();}
            now={mx.first-mn.first,mx.second};
            if((!q1.empty()&&now>q1.back())||(!q2.empty()&&now>q2.back())){
                if(cnt){
                    cout<<i+cnt-((cnt+1)&1)<<"\n";
                    return;
                }
                q2.push_back(now);
            }
            else{
                q2.push_back(now);
                cnt++;
            }
        }
        else if(!q1.empty()){
            mx=q1.front();q1.pop_front();
            mn=q1.back();q1.pop_back();
            now={mx.first-mn.first,mx.second};
            if((!q1.empty()&&now>q1.back())||(!q2.empty()&&now>q2.back())){
                if(cnt){
                    cout<<i+cnt-((cnt+1)&1)<<"\n";
                    return;
                }
                q2.push_back(now);
            }
            else{
                q2.push_back(now);
                cnt++;
            }
        }
        else if(!q2.empty()){
            mx=q2.front();q2.pop_front();
            mn=q2.back();q2.pop_back();
            now={mx.first-mn.first,mx.second};
            if((!q1.empty()&&now>q1.back())||(!q2.empty()&&now>q2.back())){
                if(cnt){
                    cout<<i+cnt-((cnt+1)&1)<<"\n";
                    return;
                }
                q2.push_back(now);
            }
            else{
                q2.push_back(now);
                cnt++;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;	cin>>T;
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    solve();
    T--;
    while(T--){
        ll k;cin>>k;
        for(ll i=1;i<=k;i++){
            ll p,now;cin>>p>>now;
            a[p]=now;
        }
        solve();
    }
    return 0;
}