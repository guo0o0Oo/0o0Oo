#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10;
int b[N]={},n,k;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar_unlocked();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar_unlocked();
    }
    while (isdigit(ch)) {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar_unlocked();
    }
    return x * f;
}

inline void write(int x) {
    if (x == 0) {
        putchar_unlocked('0');
        return;
    }
    if (x < 0) {
        putchar_unlocked('-');
        x = -x;
    }
    static char buf[20];
    int idx = 0;
    while (x) {
        buf[idx++] = '0' + (x % 10);
        x /= 10;
    }
    while (idx--) {
        putchar_unlocked(buf[idx]);
    }
}
int main(){
	n=read();k=read();
	int data;
	for(int i=1;i<=k;i++){
		data=read();
		b[data]=1;
	}
	int cnt=(n-k)*2+k,t=n+1;
	write(cnt);putchar('\n');
	for(int i=1;i<=n;i++){
		if(b[i]){
			putchar_unlocked('1');putchar_unlocked(' ');write(i);putchar_unlocked(' ');write(t-1);putchar_unlocked('\n');
			t++;
		}
		else{
			putchar_unlocked('3');putchar_unlocked(' ');write(i);putchar_unlocked('\n');
			putchar_unlocked('2');putchar_unlocked(' ');write(t-1);putchar_unlocked(' ');write(t);putchar_unlocked('\n');
			t+=2;
		}
	}
}
