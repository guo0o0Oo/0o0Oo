#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
int n,m;
pair<int,int> op[M];
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			cin>>op[i].first>>op[i].second;
		}
		sort(op+1,op+1+m);
		op[0]={0,0};
		bool flag=1;
		for(int i=1;i<=m;i++){
			if(op[i].first==op[i-1].first&&op[i].second!=op[i-1].second){
				cout<<"No"<<"\n";
				flag=0;
				break;
			}
			if(op[i-1].first+op[i].first)
		}
		if(flag){
			cout<<"Yes"<<"\n";
		}
	}
	return 0;
}

