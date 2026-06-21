#include<bits/stdc++.h>
using namespace std;
int ans[10010],zhi[10010],cnt;
bool iszhi[10010];
void init(){
    for(int i=2;i<=10000;i++){
        if(!iszhi[i]){
            for(int j=i*2;j<=10000;j+=i){
                iszhi[j]=1;
            }
        }
    }
    for(int i=2;i<=10000;i++){
        if(!iszhi[i]){
            zhi[++cnt]=i;
        }
    }
}
int main(){
    int n;
    cin>>n;
    init();
    for(int i=1;i<=n;i++){
        int nowi=i;
        for(int j=1;nowi!=1&&zhi[j]<=sqrt(n);j++){
            cout<<nowi<<"\n";
            while(nowi%zhi[j]==0){
                cout<<zhi[j];
                ans[j]++;
                nowi/=zhi[j];
            }
        }
    }
    for(int i=1;i<=cnt;i++){
        if(ans[i]){
            cout<<zhi[i]<<" "<<ans[i]<<"\n";
        }
    }
}