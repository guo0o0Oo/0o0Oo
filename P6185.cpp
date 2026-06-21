#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
set<int> g1[N],g2[N];
long long a[N],b[N],c[N];
bool ifadd2[N];
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,m,op,x,y;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cin>>b[i];
		for(int i=1;i<=n;i++)c[i]=b[i]-a[i];
		for(int i=1;i<=n;i++){g1[i].clear();g2[i].clear();}
		for(int i=1;i<=n;i++){ifadd2[i]=false;}
		for(int i=1;i<=m;i++){
			cin>>op>>x>>y;
			if(op==1&&x==y){ifadd2[x]=true;continue;}
			if(op==1){g1[x].insert(y);g1[y].insert(x);}
			else {g2[x].insert(y);g2[y].insert(x);}
		}
		bool flag=true;
		for(int i=1;i<=n;i++){
			for(const auto& pos:g1[i]){
				if(pos<i)g1[i].erase(pos);
				else if(pos==i)ifadd2[i]=true;
				else break;
			}
			for(const auto& pos:g1[i]){
				if(pos<=i)g1[i].erase(pos);
				else break;
			}
			if(ifadd2[i]&&c[i]%2==0){
				c[i]=0;
			}
			else if(g1[i].empty()&&g2[i].empty()){
				cout<<"NO\n";
				flag=0;
				break;
			}
			else if(!g1[i].empty()){
				auto low=g1[i].begin();
				c[*low]+=c[i];
				c[i]=0;
			}
			else{
				auto low=g2[i].begin();
				c[*low]-=c[i];
				c[i]=0;
			}
			if(ifadd2[i]){
				for(const auto& p:g1[i]){
					ifadd2[p]=true;
				}
				for(const auto& p:g2[i]){
					ifadd2[p]=true;
				}
			}
			for(const auto& p:g1[i]){
				for(const auto& q:g1[i]){
					g2[p].insert(q);
					g2[q].insert(p);
				}
			}
			for(const auto& p:g2[i]){
				for(const auto& q:g2[i]){
					g2[p].insert(q);
					g2[q].insert(p);
				}
			}
			for(const auto& p:g1[i]){
				for(const auto& q:g2[i]){
					g1[p].insert(q);
					g1[q].insert(p);
				}
			}
		}
		if(flag){
			cout<<"YES\n";
		}
	} 
	return 0;
}

