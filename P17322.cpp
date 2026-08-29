#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,k;
string a,b;
bool ifca[1000010],ifcb[1000010];
string cl(const string& s){
    stack<pair<char,ll> > st;
    for(char c:s){
        if(!st.empty()&&c==st.top().first)st.top().second++;
        else st.push({c,1});
        if(st.top().second==k)st.pop();
    }
    string res;
    while(!st.empty()){
        res.insert(0,st.top().second,st.top().first);
        st.pop();
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    cin>>a>>b;
    if(cl(a)==cl(b)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}