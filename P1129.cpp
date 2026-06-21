#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int G[201][201],x[201],y[201];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;	cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>G[i][j];
                if(G[i][j]){
                    x[j]++;
                    y[i]++;
                }
            }
        }
        int flag=1;
        for(int i=1;i<=n;i++){
            if((!x[i])||(!y[i])){
                cout<<"No\n";
                flag=0;
                break;
            }
        }
        if(flag){
            cout<<"Yes\n";
        }
    }
    return 0;
}