#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
const ll N=1e6+10;
ll n,v[N],l[N],r[N],size[N],ans=1;
bool check(ll ls,ll rs){
	if(ls==0&&rs==0)return 1;
	if(ls==0||rs==0)return 0;
	if(v[ls]!=v[rs])return 0;
	return check(l[ls],r[rs])&&check(r[ls],l[rs]);
}
void solve(ll node){
	if(check(l[node],r[node])){
		ans=max(size[node],ans);
		return;
	}
	else{
		solve(l[node]);
		solve(r[node]);
	}
}
void init(ll node){
    if(node==0)return;
    init(l[node]);init(r[node]);
    size[node]=size[l[node]]+size[r[node]]+1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>v[i];
	for(ll i=1;i<=n;i++){
        cin>>l[i]>>r[i];
		l[i]=max(l[i],ll(0));
		r[i]=max(r[i],ll(0));
    }
	init(1);
	solve(1);
	cout<<ans<<"\n";
	return 0;
}