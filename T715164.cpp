#include<bits/stdc++.h>
using namespace std;
const int N=1001;
short g[N][N][101],n,m,q,T,di[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main(){
    cin>>n>>m>>q>>T;
    int x,y;
    cin>>x>>y;
    g[x][y][1]=1;
    cin>>x>>y;
    g[x][y][1]=2;
    for(int k=2;k<=T;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(g[i][j][k-1]==3)g[i][j][k]=0;
                else if(g[i][j][k-1]==1||g[i][j][k-1]==2)continue;
                else{
                    bool w=0,h=0;
                    for(int ii=0;ii<4;ii++){
                        if(g[i+di[ii][0]][j+di[ii][1]][k-1]==2)w=1;
                        if(g[i+di[ii][0]][j+di[ii][1]][k-1]==1)h=1;
                    }
                    if(w&&h)g[i][j][k]=3;
                    else if(w)g[i][j][k]=2;
                    else if(h)g[i][j][k]=1;
                    else g[i][j][k]=0;
                }
            }
        }
    }
    int s[4]={};
    while(q--){
        int t,i,j;
        cin>>t>>i>>j;
        s[g[i][j][t]]++;
    }
    cout<<s[0]<<" "<<s[2]<<" "<<s[1]<<" "<<s[3]<<"\n";
}
