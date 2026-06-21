#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int h[N],cnt[N],sz=0,hei[N];
int main(){
	int n=0;
	while(cin>>h[++n]);
	n--;
	for(int i=1;i<=n;i++){
		int l=0,r=sz;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(cnt[mid]<h[i])r=mid-1;
			else l=mid;
		}
		if(l==sz){
			cnt[++sz]=h[i];
		}
		else{
			cnt[l+1]=max(h[i],cnt[l+1]);
		}
	}
	cout<<sz<<"\n";
	sz=0;
	for(int i=1;i<=n;i++){
		int l=0,r=sz+1;
		while(l<r){
			int mid=(l+r)>>1;
			if(hei[mid]>=h[i])r=mid;
			else l=mid+1;
		}
		if(l==sz+1){
			hei[++sz]=h[i];
		}
		else{
			hei[l]=h[i];
		}
	}
	cout<<sz<<"\n";
	return 0;
}
