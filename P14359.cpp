#include<bits/stdc++.h>
using namespace std;
long long n,k,data,pos,a[500010],ans=0;
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > pq;
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	pos=-1;
	for(int i=0;i<n;i++)
	{
		data=0;
		for(int j=i;j>pos;j--)
		{
			data^=a[j];
			if(data==k)
			{
				ans++;
				pos=i;
				i=j;
				break;
			}
		}
	}
	cout<<ans<<endl;
}
