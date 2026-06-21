#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
bool q[N];
void init(){
	for(int i=2;i<N;i++){
		if(q[i])continue;
		for(int j=i*2;j<N;j+=i){
			q[j]=1;
		}
	}
	for(int i=2;i<N;i++){
		if(q[i]==0){
			cout<<i<<" ";
		}
	}
}
int main(){
	freopen("ÖÊÊý.txt","w",stdout);
	init(); 
	return 0;
}

