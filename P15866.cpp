#include<bits/stdc++.h>
using namespace std;
using ll=long long;
set<ll> st;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;   cin>>T;
    ll t;	cin>>t;
    while(t--){
        ll n,a,ans=0,mina=-1;
        cin>>n;
        st.clear();
        for(ll i=1;i<=n;i++){
            cin>>a;
            mina=min(mina,a);
            st.insert(a);
            set<ll>::iterator mex=lower_bound(st.begin(),st.end(),0);
            
        }

    }
    return 0;
}