#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s;
    if(s[s.size()-1]=='e')s=s+'r';
    else s=s+"er";
    cout<<s<<"\n";
    return 0;
}