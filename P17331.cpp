#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,k,a[200010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;	cin>>T;
    while(T--){
        cin>>n>>k;
        for(ll i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        if(k==1&&a[1]==1){
            cout<<-1<<"\n";
            continue;
        }
        ll p=1,nd=0;
        for(ll i=1;i<=n;i++){
            if(a[i]<p)continue;
            if(p==k&&a[i]==k){nd++;continue;}
            else if(p==k)break;
            nd+=a[i]-p,p++;
        }
        if(p!=k){
            cout<<-1<<"\n";
            continue;
        }
        cout<<nd<<"\n";
    }
    return 0;
}