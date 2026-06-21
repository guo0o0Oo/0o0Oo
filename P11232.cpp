#include<bits/stdc++.h>
using namespace std;
long long T,n,m,L,V,d,v,a,p,ne[100005],ans=0,ce=0;
struct Spin{
	long long l,r;
}sp[100005];
bool cmp(Spin ls,Spin rs){
	return ls.r<rs.r;
}
int main(){
	cin>>T;
	while(T--){
		ans=0;
		ce=0;
		cin>>n>>m>>L>>V;
		for(int i=0;i<n;i++){
			cin>>d>>v>>a;
			if(a>0){
				if(v>V){
					sp[i].l=d;
					sp[i].r=L;
				}
				else{
					sp[i].l=d+(V-v+a-1)/a;
					sp[i].r=L;
					if(sp[i].l>L){
						sp[i].l=-1;
						sp[i].r=-1;
						continue;
					}
				}
			}
			else if(a<0){
				if(v>V){
					sp[i].l=d;
					sp[i].r=min(d+(v-V-1)/(-a),L);
				}
				else{
					sp[i].l=-1;
					sp[i].r=-1;
				}
			}
			else{
				if(v>V){
					sp[i].l=d;
					sp[i].r=L;
				}
				else{
					sp[i].l=-1;
					sp[i].r=-1;
				}
			}
		}
		sort(sp,sp+n,cmp);
		int pos=0;
		memset(ne,-1,sizeof(ne));
		for(int i=0;i<m;i++){
			cin>>p;
			for(int j=pos;j<=p;j++){
				ne[j]=p;
			}
			pos=p+1;
		}
		pos=0;
		while(sp[pos].r==-1)pos++;
		while(ne[sp[pos].r]<=sp[pos].l)pos++;
		if(pos<n){
			ans++;
			ce++;
		}
		else{
			cout<<0<<" "<<m<<endl;
			continue;
		}
		int lt=ne[sp[pos].r];
		for(int i=pos+1;i<n;i++)
		{
			if(lt>=sp[i].l){
				pos=i;
				ans++;
				continue;
			}
			while(ne[sp[pos].r]<=sp[pos].l)pos++;
			if(pos<n){
				ans++;
				ce++;
			}
			else{
				break;
			}
		}
		cout<<ans<<" "<<m-ce<<endl;
	}
	return 0;
}
