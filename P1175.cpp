#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
struct st{
    bool if_op;
    ll fig;
    char op;
};
list<char> op;
list<st> res;
string s;
ll lev(char ch){
    switch(ch){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        case '(':
        case ')':
            return 0;
        case '@':
            return inf;
    }
}
ll com(ll a,ll b,char ch){
    switch(ch){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
        case '^':
            return pow(a,b);
    }
}
void solve(){
    for(list<st>::iterator it=res.begin();it!=res.end();it++){
        if(it->if_op){
            char ch=it->op;
            list<st>::iterator data=it;
            list<st>::iterator it1=prev(data);
            list<st>::iterator it2=prev(it1);
            ll ans=com(it2->fig,it1->fig,ch);
            it1->fig=ans;
            res.erase(it2);
            res.erase(data);
            break;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s;
    s+='@';
    for(ll i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')res.push_back({0,s[i]-'0','0'});
        else if(s[i]=='('){
            op.push_back(s[i]);
        }
        else if(s[i]==')'){
            while(op.back()!='('){
                res.push_back({1,0,op.back()});
                op.pop_back();
            }
            op.pop_back();
        }
        else if(s[i]=='^'){
            op.push_back(s[i]);
        }
        else{
            while(!op.empty()&&lev(op.back())>=lev(s[i])){
                res.push_back({1,0,op.back()});
                op.pop_back();
            }
            op.push_back(s[i]);
        }
    }
    while(res.size()>1){
        for(st i:res){
            if(i.if_op)cout<<i.op<<" ";
            else cout<<i.fig<<" ";
        }
        cout<<"\n";
        solve();
    }
    cout<<res.front().fig;
    return 0;
}