#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(__int128 i=a;i<=b;i++)
__int128 n,k;
pair<__int128,__int128> a[1010];
priority_queue<__int128,vector<__int128>,greater<__int128> > pq;
__int128 read(){
    __int128 x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')f=-1,ch=getchar();
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return f*x;
}
void print(__int128 x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);//注意这里是x>9不是x>10 
    putchar(x%10+'0');
}
int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    n=read();k=read();
    F(i,1,n)a[i].first=read();
    F(i,1,n)a[i].second=read();
    sort(a+1,a+n+1);
    __int128 ans=1e28;
    F(i,k,n){
        while(!pq.empty())pq.pop();
        F(j,1,i-1)pq.push(a[j].second*(a[i].first-a[j].first));
        __int128 res=0;
        F(j,1,k-1)res+=pq.top(),pq.pop();
        ans=min(ans,res);
    }
    print(ans);
    return 0;
}