#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll a[100010],b[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;	cin>>t;
    while(t--){
        ll n,mina=sup,sum=0;
        cin>>n;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
            mina=min(a[i],mina);
        }
        ll l=-1,r=mina+1;
        if(n%2){
            while(l<r){
                ll mid=(l+r)>>1;
                ll flag;//0->up,1->down
                for(ll i=1;i<=n;i++)b[i]=a[i]-mid;
                for(ll i=1;i<n;i++){
                    if(b[i]<0){
                        flag=1;
                        break;
                    }
                    b[i+1]-=b[i];
                }
                if(b[n]>0)flag=0;
                else flag=1;
                if(flag){
                    r=mid;
                }
                else{
                    l=mid+1;
                }
            }
            if(l>=0&&l<=mina){
                cout<<sum-n*l<<"\n";
            }
            else{
                cout<<"-1"<<"\n";
            }
        }
        else{
            while(l<r){
                ll mid=(l+r)>>1;
                ll flag;//0->up,1->down
                for(ll i=1;i<=n;i++)b[i]=a[i]-mid;
                for(ll i=1;i<n;i++){
                    if(b[i]<0){
                        flag=1;
                        break;
                    }
                    b[i+1]-=b[i];
                }
                if(b[n]==0)flag=0;
                else flag=1;
                if(flag){
                    r=mid;
                }
                else{
                    l=mid+1;
                }
            }
            if(l>=0&&l<=mina){
                cout<<sum-n*l<<"\n";
            }
            else{
                cout<<"-1"<<"\n";
            }
        }
    }
    return 0;
}