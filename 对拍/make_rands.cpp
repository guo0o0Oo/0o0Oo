#include<bits/stdc++.h>
#define rand(a,b) (rand()%((b)-(a)+1)+(a))
using namespace std;
int main(){
	srand(time(0));
	int n=5,k=2;
	cout<<n<<" "<<k<<"\n";
	for(int i=1;i<=n;i++){
		int a=rand(1,20);
		cout<<a<<" "<<rand(a,20)<<"\n";
	}
	return 0;
}
