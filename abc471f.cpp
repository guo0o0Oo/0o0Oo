#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e5+10;
ll n,k,zerocnt[N];
string s[N];
bool cmp1(string a,string b){
    return a.size()>b.size();
}
bool cmp2(string a,string b){
    return a[0]>b[0];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(ll i=1;i<=n;i++)cin>>s[i];
    sort(s+1,s+n+1,cmp1);
    ll cnt=0,l;
    s[0]="";
    for(ll i=1;i<=n;i++){
        if(s[i].size()==s[i-1].size())cnt++;
        else if(cnt>=k)break;
    }
    l=s[cnt].size();
    ll mxl=0;
    for(ll i=n;i>=1;i--){
        if(i>cnt){
            while(s[i][0]=='0')s[i].erase(0,1);
        }
    }
    if(cnt!=k){
        for(ll i=1;i<=n;i++){
            if(s[i].size()==s[cnt].size())cnt=i-1;
        }
    }
    sort(s+1,s+n+1,cmp1);
    for(ll i=1;i<=cnt;i++){
        for(ll j=0;j<s[i].size();j++){
            if(s[i][j]=='0')zerocnt[i]++;
            else break;
        }
    }
    for(ll i=1;i<=n;i++){
        
    }
    return 0;
}