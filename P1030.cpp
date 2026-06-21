#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
string s1,s2;
void pr(string s1,string s2){
    if(s1.empty()||s1.empty())return;
    char root=s2[s2.size()-1];
    ll pos=s1.find(root);
    cout<<root;
    pr(s1.substr(0,pos),s2.substr(0,pos));
    pr(s1.substr(pos+1),s2.substr(pos,s2.size()-pos-1));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s1>>s2;
    pr(s1,s2);
    return 0;
}