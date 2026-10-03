#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
string s;
ll cnt[10];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s;
    for(ll i=0;i<s.size();i++){
        if(i==0||s[i-1]=='|'){
            cnt[s[i]-'A']++;
        }
    }
    ll cnt1,cnt2;
    cnt1=cnt[0]+cnt[3]+cnt[4];
    cnt2=cnt[2]+cnt[5]+cnt[6];
    if(cnt1==cnt2){
        if(s[s.size()-1]=='A')cout<<"A-mol";
        else cout<<"C-dur";
    }
    else if(cnt1>cnt2){
        cout<<"A-mol";
    }
    else{
        cout<<"C-dur";
    }
    return 0;
}