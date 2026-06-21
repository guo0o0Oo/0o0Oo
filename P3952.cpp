#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll m[110],cnt;
string name[110];
// 辅助函数：比较两个非负数字符串的大小
bool greaterOrEqual(const string& a, const string& b) {
    if (a.length() != b.length()) 
        return a.length() < b.length();
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) 
            return a[i] < b[i];
    }
    return true; // 相等
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;	cin>>t;
    while(t--){
        memset(m,0,sizeof(m));
        cnt=0;
        ll n,ans=0;
        string res;
        bool err=0;
        cin>>n>>res;
        while(n--){
            char op;
            cin>>op;
            if(err){
                if(op=='F'){
                    string x,y,z;
                    cin>>x>>y>>z;
                }
                continue;
            }
            if(op=='F'){
                string liang;
                cin>>liang;
                for(ll i=1;i<=cnt;i++){
                    if(name[i]==liang){
                        err=1;
                    }
                }
                cnt++;
                name[cnt]=liang;
                string x,y;
                cin>>x>>y;
                if(x!="n"&&y=="n"){
                    m[cnt]=1;
                }
                else if(x!="n"&&y!="n"){
                    if(greaterOrEqual(x,y))m[cnt]=0;
                    else m[cnt]=-1;
                }
                else if(x=="n"&&y=="n"){
                    m[cnt]=0;
                }
                else m[cnt]=-1;
                ll k=0;
                for(ll i=1;i<=cnt;i++){
                    if(m[i]==-1)break;
                    k+=m[i];
                }
                ans=max(ans,k);
            }
            if(op=='E'){
                if(cnt-1<0){
                    err=1;
                    continue;
                }
                cnt--;
            }
        }
        if(cnt!=0){
            err=1;
        }
        if(!err){
            string tans;
            if(ans==0){
                tans="O(1)";
            }
            else{
                tans="O(n^";
                string ss="";
                while(ans){
                    if(ans<0)break;
                    ss=to_string(ans%10)+ss;
                    ans/=10;
                }
                tans+=ss;
                tans+=")";
            }
            if(tans==res){
                cout<<"Yes\n";
            }
            else cout<<"No\n";
        }
        if(err){
            cout<<"ERR\n";
        }
    }
    return 0;
}