#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e5+10;
ll a[N];
bool if_c[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;	cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s1,s2,s3;
        cin>>s1>>s2>>s3;
        ll lasts1=0,earlys2=n+1;
        for(ll i=1;i<=n;i++){
            if(s1[i-1]=='1')lasts1=i;
            if(s2[i-1]=='1')earlys2=min(earlys2,i);
            if((s1[i-1]=='1'||s2[i-1]=='1')&&s3[i-1]=='1'){lasts1=n+1;earlys2=0;break;}
        }
        if(lasts1>earlys2||s3[0]=='1'||s3[n-1]=='1'){
            cout<<-1<<"\n";
            continue;
        }
        ll k=earlys2;
        for(ll i=1;i<=k;i++){
            if(i==k)a[i]=n;
            else a[i]=i;
        }
        for(ll i=k;i>=1;i--){
            while(s3[i-1]=='1')swap(a[i],a[i-1]),i--;
        }
        memset(if_c,0,sizeof(if_c));
        ll mink=k,maxk=n-1;
        for(ll i=k+1;i<=n;i++){
            while(if_c[mink])mink++;
            while(if_c[maxk])maxk--;
            if(s2[i-1]=='1'){
                a[i]=maxk;
                if_c[maxk]=1;
                continue;
            }
            a[i]=mink;
            if_c[mink]=1;
        }
        for(ll i=1;i<=n;i++)cout<<a[i]<<" ";
        cout<<"\n";
    }
    return 0;
}