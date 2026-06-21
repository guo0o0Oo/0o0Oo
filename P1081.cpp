#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define lowbit(x) ((x)&-(x))
const int N=1e5+10;
struct travel{
    ll des,far;
}A[N],B[N];//self,0->empty
struct jump{
	ll Ades,Aafar,Abfar,Bdes,Bafar,Bbfar;
}G[N][40];

ll high[N],rk[N],rerk[N],T[N],n;
pair<ll,ll> cmp[N];
void change(int pos,int d){
    while(pos<=n){
        T[pos]+=d;
        pos+=lowbit(pos);
    }
}
ll ask(int pos){
    ll res=0;
    while(pos){
        res+=T[pos];
        pos-=lowbit(pos);
    }
    return res;
}
int find(int pos){
    int l=1,lr=pos,rl=pos,r=n;
    int res=-1;
    ll k=ask(pos);
    if(k!=0){
        while(l<lr){
            int mid=(l+lr)>>1;
            if(ask(mid)<k){
                l=mid+1;
            }
            else{
                lr=mid;
            }
        }
        res=l;
    }
    if(ask(n)-k!=0){
        while(rl<r){
            int mid=(rl+r+1)>>1;
            if(ask(mid)>k+1){
                r=mid-1;
            }
            else{
                rl=mid;
            }
        }
		if(res==-1){
			res=r;
		}
        else if(cmp[pos].first-cmp[res].first>cmp[r].first-cmp[pos].first){
            res=r;
        }
    }
    return res;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>high[i];
        cmp[i].first=high[i];
        cmp[i].second=i;
    }
    sort(cmp+1,cmp+n+1);
    for(int i=1;i<=n;i++){
        rk[cmp[i].second]=i;
        rerk[i]=cmp[i].second;
    }
    A[n]={n,0};
    B[n]={n,0};
    for(int i=n-1;i>=1;i--){
        change(rk[i+1],1);
        int pos1=find(rk[i]);
        change(pos1,-1);
        int pos2=find(rk[i]);
        change(pos1,1);
        A[i]={rerk[pos1],abs(high[rerk[pos1]]-high[i])};
        if(pos2!=-1)B[i]={rerk[pos2],abs(high[rerk[pos2]]-high[i])};
        else B[i]={i,0};
    }
	for(int i=1;i<=n;i++){
		G[i][0]={A[i].des,A[i].far,0,B[i].des,0,B[i].far};
	}
	for(int i=n;i>=1;i--){
		int lastApos=G[i][0].Ades;
		int lastBpos=G[i][0].Bdes;
		jump AB=G[lastApos][0],BA=G[lastBpos][0];
		G[i][1]={AB.Bdes,G[i][0].Aafar,AB.Bbfar,BA.Ades,BA.Aafar,G[i][0].Bbfar};
	}
	for(int i=n;i>=1;i--){
		for(int j=2;j<=30;j++){
			int lastApos=G[i][j-1].Ades;
			int lastBpos=G[i][j-1].Bdes;
			jump AA=G[lastApos][j-1],BB=G[lastBpos][j-1];
			G[i][j]={AA.Ades,G[i][j-1].Aafar+AA.Aafar,G[i][j-1].Abfar+AA.Abfar,BB.Bdes,G[i][j-1].Bafar+BB.Bafar,G[i][j-1].Bbfar+BB.Bbfar};
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<5;j++){
			auto k=G[i][j];
			for(int ii=0;ii<j;ii++)cout<<"\t";
			cout<<k.Ades<<" "<<k.Aafar<<" "<<k.Abfar<<"\n";
			for(int ii=0;ii<j;ii++)cout<<"\t";
			cout<<k.Bdes<<" "<<k.Bafar<<" "<<k.Bbfar<<"\n\n";
		}
	}
}
/*4
2 3 1 4
3
4
1 3
2 3
3 3
4 3
*/
