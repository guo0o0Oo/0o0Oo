#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e5+10;
#define f(i,a,b) for(ll i=a;i<=b;i++)
deque<ll> q;
ll n,a[N],l[N],r[N],s[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    f(i,1,n)cin>>a[i];
    f(i,1,n)s[i]=s[i-1]+a[i];
    q.push_back(0);
    f(i,1,n+1){
        while(a[q.back()]>a[i]){r[q.back()]=i-1;q.pop_back();}
        if(a[i]==a[q.back()])l[i]=l[q.back()];
        else l[i]=q.back();
        q.push_back(i);
    }
    ll ans=0;
    f(i,1,n)ans=max(ans,a[i]*(s[r[i]]-s[l[i]]));
    cout<<ans<<"\n";
    return 0;
}