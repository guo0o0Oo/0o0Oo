#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
using ll=long long;
char name[10]="func",com[100];
int main(){
    ll l,r;cin>>l>>r;
    for(ll i=l;i<=r;i++){
        cout<<"TESTING:"<<i<<"\n";
        sprintf(com,"%s.exe < %s%d.in > ans%d.txt",name,name,i,i);
        system(com);
        sprintf(com,"fc %s%d.ans ans%d.txt",name,i,i);
        if(system(com)==0)cout<<"AC"<<"\n\n";
        else cout<<"WA!!"<<"\n\n";
    }
}