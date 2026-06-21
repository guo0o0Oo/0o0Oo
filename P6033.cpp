#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
queue<ll> q1,q2;
ll cnt[100010];
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
    int n,f;
    read(n);
    for(ll i=1;i<=n;i++){
        read(f);
        cnt[f]++;
    }
    for(ll i=1;i<=100000;i++){
        while(cnt[i]){
            q1.push(i);
            cnt[i]--;
        }
    }
    ll ans=0,k=-1;
    for(ll i=1;i<=2*(n-1);i++){
        if(k==-1){
            if(q1.empty()){
                k=q2.front();
                q2.pop();
            }
            else if(q2.empty()){
                k=q1.front();
                q1.pop();
            }
            else{
                if(q1.front()<q2.front()){
                    k=q1.front();
                    q1.pop();
                }
                else{
                    k=q2.front();
                    q2.pop();
                }
            }
        }
        else{
            if(q1.empty()){
                k+=q2.front();
                q2.pop();
            }
            else if(q2.empty()){
                k+=q1.front();
                q1.pop();
            }
            else{
                if(q1.front()<q2.front()){
                    k+=q1.front();
                    q1.pop();
                }
                else{
                    k+=q2.front();
                    q2.pop();
                }
            }
            ans+=k;
            q2.push(k);
            k=-1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}