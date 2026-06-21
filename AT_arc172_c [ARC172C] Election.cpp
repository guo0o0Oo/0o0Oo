#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a,n,ans=1;
int main()
{
	char ch,lch;
	cin>>n;
	cin>>lch;a=lch=='A'?1:-1;
	for(int i=1;i<n;i++)
	{
		cin>>ch;
		if(ch=='A')
		{
			++a;
		}
		else
		{
			--a;
		}
		if(ch!=lch&&a>=-1&&a<=1)ans++;
		lch=ch;
	}
	cout<<ans;
}
