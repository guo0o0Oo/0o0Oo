#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int l[200010],maxa[200010],smaxa[200010];
vector<int> a[200010];
int main(){
    int t;	cin>>t;
    while(t--){
        int n,in;
        cin>>n;
        memset(maxa,-1,sizeof(maxa));
        memset(smaxa,-1,sizeof(smaxa));
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=0;j<l[i];j++){
                cin>>in;
                a[i].push_back(in);
            }
            sort(a[i].begin(),a[i].end());
            int last=0;
            for(int j=0;j<l[i];j++){
                if(smaxa[i]!=-1)break;
                while(a[i][j]!=last){
                    if(maxa[i]==-1)maxa[i]=last;
                    else if(smaxa[i]==-1)smaxa[i]=last;
                    last++;
                    if(smaxa[i]!=-1)break;
                }
                last++;
            }
            if(maxa[i]==-1){
                maxa[i]=last;
                smaxa[i]=last+1;
            }
            else if(smaxa[i]==-1){
                smaxa[i]=last;
            }
        }
        for(int i=1;i<=n;i++){
            cout<<maxa[i]<<" "<<smaxa[i]<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}