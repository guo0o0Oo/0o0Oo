#include<bits/stdc++.h>
using namespace std;
const int N=(500+10)*(500+10);
#define Loop(i,A,x) for(i=A[x];i!=x;i=A[i])
int U[N],D[N],L[N],R[N],tot;
int first[N],siz[N],col[N],row[N];
int stk[N],ans;
int n,m;
void build(){
	for(int i=0;i<=m;i++){
		L[i]=i-1;R[i]=i+1;
		U[i]=D[i]=i;
	}
	L[0]=m;R[m]=0;
	tot=m;
}
void insert(int r,int c){
	tot++;siz[c]++;
	col[tot]=c;row[tot]=r; 
	U[tot]=c;
	D[tot]=D[c];
	U[D[c]]=tot;
	D[c]=tot;
	if(!first[r]){
		first[r]=L[tot]=R[tot]=tot;
	}
	else{
		L[tot]=first[r];
		R[tot]=R[first[r]];
		L[R[first[r]]]=tot;
		R[first[r]]=tot;
	}
}
void remove(int c){
	int i,j;
	L[R[c]]=L[c];
	R[L[c]]=R[c];
	Loop(i,D,c){
		Loop(j,R,i){
			U[D[j]]=U[j];
			D[U[j]]=D[j];
			--siz[col[j]];
		}
	}
}
void recover(int c){
	int i,j;
	L[R[c]]=c;
	R[L[c]]=c;
	Loop(i,U,c){
		Loop(j,L,i){
			U[D[j]]=j;
			D[U[j]]=j;
			++siz[col[j]];
		}
	}
}
bool dance(int dep){
	if(!R[0]){
		ans=dep;
		return true;
	}
	int i,j,c=R[0];
	Loop(i,R,0)
		if(siz[i]<siz[c])c=i;
	remove(c);
	Loop(i,D,c){
		stk[dep]=row[i];
		Loop(j,R,i)remove(col[j]);
		if(dance(dep+1))return true;
		Loop(j,L,i)recover(col[j]);
	}
	recover(c);
	return false;
}
int main(){
	cin>>n>>m;
	build();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			bool x;
			cin>>x;
			if(x)insert(i,j);
		}
	}
	dance(1);
	if(ans){
		for(int i=1;i<ans;i++){
			cout<<stk[i]<<" ";
		}
	}
	else{
		cout<<"No Solution!";
	}
	return 0;
}

