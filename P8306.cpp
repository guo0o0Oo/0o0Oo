#include<bits/stdc++.h>
using namespace std;
using ll=int;
ll trie[3000010][62];
ll pass[3000010];
ll n,q,tot;
inline ll code(char ch){
    if(ch>='0'&&ch<='9')return ch-'0';
    if(ch>='a'&&ch<='z')return ch-'a'+10;
    return ch-'A'+36;

}
void insert(const string& s){
    ll p=0;
    for(char ch:s){
        if(!trie[p][code(ch)])trie[p][code(ch)]=++tot;
        p=trie[p][code(ch)];
        pass[p]++;
    }
}
ll query(const string& s){
    ll p=0;
    for(char ch:s){
        if(!trie[p][code(ch)])return 0;
        p=trie[p][code(ch)];
    }
    return pass[p];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;	cin>>T;
    while(T--){
        while(tot){
            memset(trie[tot],0,sizeof(trie[tot]));
            pass[tot]=0;
            tot--;
        }
        memset(trie[0],0,sizeof(trie[0]));
        pass[0]=0;
        cin>>n>>q;
        for(ll i=1;i<=n;i++){
            string s;
            cin>>s;
            insert(s);
        }
        for(ll i=1;i<=q;i++){
            string s;
            cin>>s;
            cout<<query(s)<<"\n";
        }
    }
    return 0;
}