#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
string a,b;
vector<ll> zfunc(const string& s){
    ll n=s.size();
    vector<ll> z(n);
    if(n==0)return z;
    z[0]=n;
    ll l=0,r=0;
    for(ll i=1;i<s.size();i++){
        if(i<=r)z[i]=min(z[i-l],r-i+1);
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
        if(i+z[i]-1>r)l=i,r=i+z[i]-1;
    }
    return z;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>a>>b;
    string s;
    s.reserve(a.size()+1+b.size());
    s+=b;s+='@';s+=a;
    ll res1=0,res2=0;
    {
        auto z1=zfunc(b);
        for(ll i=0;i<b.size();i++){
            res1^=(i+1)*(z1[i]+1);
        }
    }
    {
        auto z2=zfunc(s);
        for(ll i=b.size()+1;i<s.size();i++){
            res2^=(i-b.size())*(z2[i]+1);
        }
    }
    cout<<res1<<"\n"<<res2<<"\n";
    return 0;
}