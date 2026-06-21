#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct Pig{
    string ide;
    ll card_cnt[27];
    string card;
    ll health;
    Pig():health(4){}
}pig[15];
ll n,m,pos;
string lib;
void init(){
    cin>>n>>m;
    char ch;
    for(ll i=1;i<=n;i++){
        cin>>pig[i].ide;
        if(pig[i].ide=="ZP")pos=i;
        for(ll j=1;j<=4;j++){
            cin>>ch;
            pig[i].card_cnt[ch-'A']++;
            pig[i].card+=ch;
        }
    }
    for(ll i=1;i<=m;i++){
        cin>>ch;
        lib+=ch;
    }
}
inline void get_card(){
    for(ll i=1;i<=2;i++){
        pig[pos].card_cnt[lib[0]-'A']++;
        pig[pos].card+=lib[0];
        lib.erase(0,1);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    init();
    bool if_end=0;
    while(!if_end){
        get_card();
        

    }
    return 0;
}