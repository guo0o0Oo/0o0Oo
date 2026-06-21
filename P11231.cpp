#include<bits/stdc++.h>
using namespace std;
int n,r[100005],p=0,ans;
int main(){
	cin>>n;
	ans=n;
	for(int i=0;i<n;i++)
	{
		cin>>r[i];
	}
	sort(r,r+n);
	for(int i=1;i<n;i++)
	{
		if(r[p]<r[i])
		{
			r[p]=INT_MAX;
			ans--;
			while(r[p]==INT_MAX)p++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
