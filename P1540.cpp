#include<bits/stdc++.h>
using namespace std;
int n,m;
deque<int> q; 
int main(){
	cin>>m>>n;
	int a,sum=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		bool flag=1;
		for(auto k:q){
			if(k==a){
				flag=0;
				break;
			}
		}
		if(flag){
			if(q.size()==m)q.pop_front();
			q.push_back(a);
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

