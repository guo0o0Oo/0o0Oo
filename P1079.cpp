#include<bits/stdc++.h>
using namespace std;
string key,s;
int cnt(char ch){
    if(ch>='a')return ch-'a';
    else return ch-'A';
}
int a[1010],len,pos;
int main(){
    cin>>key>>s;
    len=key.size();
    pos=0;
    for(int i=0;i<len;i++){
        a[i]=cnt(key[i]);
    }
    for(int i=0;i<s.size();i++){
        if(s[i]>='a'){
            if(s[i]-a[pos]<'a'){
                s[i]+=26-a[pos];
            }
            else{
                s[i]-=a[pos];
            }
        }
        else{
            if(s[i]-a[pos]<'A'){
                s[i]+=26-a[pos];
            }
            else{
                s[i]-=a[pos];
            }
        }
        pos=(pos+1)%len;
    }
    cout<<s;
    return 0;
}