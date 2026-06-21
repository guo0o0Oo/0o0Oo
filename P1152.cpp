#include<bits/stdc++.h>
using namespace std;
bool dance[1010];
int main(){
	int n,a,olda;
	cin>>n;
	cin>>olda;
	for(int i=1;i<n;i++){
		cin>>a;
		if(abs(a-olda)>=n||dance[abs(a-olda)]){
			cout<<"Not jolly";
			return 0;
		}
		olda=a;
	}
	cout<<"Jolly";
	return 0;
}
