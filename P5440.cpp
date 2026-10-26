#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,sum,md[100]={0,103,107,113,131,211,223,307,311,313,317,331,419,503,523,607
    ,613,617,619,719,811,823,829,907,911,919,929,1013,1019,1031,1103,1117,1123,1129,1213,1217,1223,1229,1231};
string ans[1500000];
string a;
bool ifcr(ll x){
    for(ll i=2;i<=sqrt(x);i++)if(x%i==0)return 0;
    return 1;
}
void init(){
    for(ll i=1;i<=9999;i++){
        if((i%400==0||(i%4==0&&!(i%100==0)))&&ifcr(i*10000+229)){
            ans[++sum]=i/1000+'0';
            ans[sum]+=(i%1000-i%100)/100+'0';
            ans[sum]+=(i%100-i%10)/10+'0';
            ans[sum]+=i%10+'0';
            ans[sum]+="0229";
        }
    }
    for(ll i=1;i<=38;i++){
        for(ll j=1;j<=9999;j++){
            if(ifcr(j*10000+md[i])){
                ans[++sum]=j/1000+'0';
                ans[sum]+=(j%1000-j%100)/100+'0';
                ans[sum]+=(j%100-j%10)/10+'0';
                ans[sum]+=j%10+'0';
                ans[sum]+=md[i]/1000+'0';
                ans[sum]+=(md[i]%1000-md[i]%100)/100+'0';
                ans[sum]+=(md[i]%100-md[i]%10)/10+'0';
                ans[sum]+=md[i]%10+'0';
            }
        }
    }
}
bool cmp(ll k){
    for(ll i=0;i<=7;i++){
        if(a[i]=='-')continue;
        if(a[i]!=ans[k][i])return 0;
    }
    return 1;
}
ll solve(){
    ll cnt=0;
    for(ll i=1;i<=sum;i++){
        if(cmp(i))cnt++;
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    init();
    ll T;	cin>>T;
    while(T--){
        cin>>a;
        cout<<solve()<<"\n";
    }
    return 0;
}