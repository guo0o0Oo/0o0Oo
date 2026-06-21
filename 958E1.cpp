#include<bits/stdc++.h>
using namespace std;

int n,r,pos[11][2],opos[11][2];

int main(){
    cin>>n>>r;
    for(int i=1;i<=n;i++){
        cin>>pos[i][0]>>pos[i][1];
    }
    for(int i=1;i<=r;i++){
        cin>>pos[i][0]>>pos[i][1];
    }
    if(n!=r){
        cout<<"No"<<"\n";
        return 0;
    }
    cout<<"Yes"<<"\n";
    return 0;
}