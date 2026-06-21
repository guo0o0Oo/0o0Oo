#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
double a[maxn],b[maxn],c[maxn];
int n;
double f(double x){
	double ans=-1e18;
	for(int i=1;i<=n;i++){
		ans=max(ans,a[i]*x*x+b[i]*x+c[i]);
	}
	return ans;
} 
int main(){
	int ts;cin>>ts;
	while(ts--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		double l=0,r=1000;
		while(r-l>=1e-9){
			double x=(l*2+r)/3,y=(l+r*2)/3;
			if(f(x)>f(y)){
				l=x;
			}
			else{
				r=y;
			}
		}
		printf("%.4f\n",f(l));
	}
	return 0;
} 
