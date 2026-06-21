#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    cin>>s;
    ll alcnt=0,maxcnt=0,ncnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='G'){
            alcnt++;
            ncnt++;
            maxcnt=max(maxcnt,ncnt);
            continue;
        }
        ncnt=0;
    }
    maxcnt=max(maxcnt,ncnt);
    ll withouts=0,all=0,haves=0,maxall=0;
    for(int i=0;i<n;i++){
        if(s[i]=='G'){
            if(!haves)withouts++;
            all++;
            maxall=max(maxall,all);
        }
        if(s[i]=='S'){
            if(haves==1){
                if(s[i-1]=='G'){
                    all-=withouts;
                    withouts=all;
                }
                else{
                    haves=0;
                    all=0;
                    withouts=0;
                }
            }
            haves=1;
        }
    }
    if(alcnt-maxall){
        cout<<maxall+1<<"\n";
    }
    else{
        cout<<maxall<<"\n";
    }
    return 0;
}