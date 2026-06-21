#include<bits/stdc++.h>
using namespace std;
bool G[1010][1010],vis[1010][1010];
char c;
int n,m;
int seek(int x,int y){
    if(!G[x][y]||vis[x][y])return 0;
    vis[x][y]=1;
    int res=seek(x-1,y)+seek(x+1,y)+seek(x,y+1)+seek(x,y-1)+1;
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>c;
            if(c=='.'){
                G[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!G[i][j]){
                memset(vis,0,sizeof(vis));
                cout<<(seek(i-1,j)+seek(i+1,j)+seek(i,j+1)+seek(i,j-1)+1)%10;
            }
            else{
                cout<<".";
            }
        }
        cout<<"\n";
    }
}