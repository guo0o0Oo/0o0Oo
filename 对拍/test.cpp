#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
using ll=long long;
char NAME[10]="file";
int main(){
	int l,r;
	cin>>l>>r;
	char com[100];
	for(ll i=l;i<=r;i++){
		cout<<"TESTING:"<<i<<"\n";
		sprintf(com,"%s.exe < %s%d.in > ans%d.txt",NAME,NAME,i,i);
		system(com);
		sprintf(com,"fc %s%d.ans ans%d.txt",NAME,i,i);
		if(system(com)==0)cout<<"AC\n\n";
		else cout<<"WA!!";
	}
	system("pause");
	return 0;
}