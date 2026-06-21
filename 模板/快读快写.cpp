#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	int neg=0;
	x=0;
	char ch=getchar();
	while(isspace(ch)){
		ch=getchar();
	}
	if(ch=='-'){
		neg=1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	if(neg){
		x=-x;
	}
}
void write(int x){
	if(x==0){
		putchar('0');
		return;
	}
	if(x<0){
		putchar('-');
		x=-x;
	}
	static int sta[20];
	int top=0;
	while(x){
		sta[top++]=x%10;
		x/=10;
	}
	while(top){
		putchar('0'+sta[--top]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a,n,ans=0;
	read(n);
	for(int i=1;i<=n;++i){
		read(a);
		ans+=a;
	}
	write(ans);
}
