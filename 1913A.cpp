#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n;
    string s;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>s;
        bool flag=1;
        for(ll j=1;j<s.size();j++){
            if(s[j]!='0'){
                int x=stoi(s.substr(0,j)),y=stoi(s.substr(j,s.size()-j+1));
                if(x<y){
                    flag=0;
                    cout<<x<<" "<<y<<"\n";
                    break;
                }
            }
        }
        if(flag)
        cout<<-1<<"\n";
    }
    return 0;
}